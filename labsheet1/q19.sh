echo "Enter file name within the same folder: "
IFS='.' read -p 'Enter file name : ' nm ext
caps=`echo ${nm^^}`
`mv $nm"."$ext $caps"."$ext`
