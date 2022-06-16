import sys
from pathlib import Path

def anchorstring(str):
    doxyref=str.replace("/", "")
    # can't simply use lower() as github-markdown retains non-leading uppercase characters
    # so lowercase only every char after a space:
    drwords = doxyref.split(" ")
    doxyref = ""
    i = 0
    while i < len(drwords):
        if len(drwords[i]) != 0:
            doxyref = doxyref+drwords[i][0].lower() + drwords[i][1:]
        if i < len(drwords)-1:
           doxyref=doxyref+"-"
        i=i+1
    return doxyref

if len(sys.argv) != 3 or not Path(sys.argv[1]).is_file():
   print("Expecting original and new file location. Exiting.")
   exit(1)

infile = open(sys.argv[1], 'r')
lines = infile.readlines()

with open(sys.argv[2], "w") as outfile:
    # ll is last line: can only be written when anchor property is known
    ll = None
    possibleanchor = None
    for line in lines:
        nl = line
        if line.startswith("#"):
            # space must exist
            si = line.index(" ")
            doxyref=anchorstring(line[si+1:].strip())
            nl = line[0:si] + " " + line[si+1:].strip() + " {#"+doxyref+"}\n"
        elif nl.startswith("==="):
            # previous line is anchor
            ll = possibleanchor
        else:
            possibleanchor=line.strip()+" {#"+anchorstring(line.strip())+"}\n"
        if ll is not None: outfile.write(ll)
        ll = nl
    outfile.write(ll)
