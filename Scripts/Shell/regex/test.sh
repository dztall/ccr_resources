#!/bin/bash
#!/bin/bash
a && b
g && j || h && s
g&&j||h&&s

function strippath()
{
    realpath1=$(readlink -f $1)
    pathdir1=$(dirname "$realpath1")
    pathdir1="$pathdir1/"
    echo $pathdir1
}

if [[ -d $path ]]; then
    echo $path is a directory
    stripped=$(strippath $path)
    pathreal=$(readlink -f $path)
    mapfile -d '' -t filesreal < <(find "${pathreal[0]}" -type f -print0)
    mapfile -d '' -t dirsreal < <(find "${pathreal[0]}" -type d -print0)
    echo execute function: preinitmulti
    count=1
    for i in ${!filesreal[@]} ; do
    pathdir=$(dirname "${filesreal[i]}")
    pathdir="$pathdir/"
    pathbase=("${filesreal[i]#$pathdir}")
    pathstripped=("${pathdir#$stripped}")
    echo
    echo "execute function: objectconvertMulti with arguments (full file path:) ${filesreal[i]}, (identifier to avoid object collisions:) $i, (directory to be created on extraction:) $pathstripped, (file to be created on extraction:) ${pathbase[0]}"
    echo
    echo ${filesreal[i]} processed
    done
    echo execute function: fin
    echo execute function: compilemulti
    echo execute function: finishmulti
    exit
fi

path=$@
