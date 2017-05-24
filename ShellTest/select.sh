#! /bin/sh

select i in "yongcheng" "wuhan" "shenzhen" "zhengzhou" "exit"
do
case $i in
    "yongcheng")
        echo "high school"
        ;;
    "wuhan")
        echo "university"
        ;;
    "shenzhen")
        echo "working in first five years"
        ;;
    "zhengzhou")
        echo "maybe come back to in future"
        ;;
    "exit")
        echo "exit select-case"
        exit 0
        ;;
    *)
        echo "unknown message"
        ;;
esac
done
