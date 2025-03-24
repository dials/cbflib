
import pycbf
object = pycbf.cbf_handle_struct() # FIXME
object.read_file(b"../img2cif_packed.cif",pycbf.MSG_DIGEST)
object.rewind_datablock()
print("Found",object.count_datablocks(),"blocks")
object.select_datablock(0)
print("Zeroth is named",object.datablock_name())
object.rewind_category()
categories = object.count_categories()
for i in range(categories):
    print("Category:",i, end=' ')
    object.select_category(i)
    category_name = object.category_name()
    print("Name:",category_name, end=' ')
    rows=object.count_rows()
    print("Rows:",rows, end=' ')
    cols = object.count_columns()
    print("Cols:",cols)
    loop=1
    object.rewind_column()
    while loop==1:
        column_name = object.column_name()
        print("column name \"",column_name,"\"", end=' ')
        try:
           object.next_column()
        except:
           break
    print
    for j in range(rows):
        object.select_row(j)
        object.rewind_column()
        if j==0: print()
        print("row:",j)
        for k in range(cols):
            name=object.column_name()
            print("col:",name, end=' ')
            object.select_column(k)
            typeofvalue=object.get_typeofvalue()
            print("type:",typeofvalue)
            if typeofvalue.find(b"bnry") > -1:
                print("Found the binary!!", end=' ')
                s=object.get_integerarray_as_string()
                print(type(str(s)))
                print(dir(str(s)))
                print(len(s))
                try:
                   import numpy 
                   d = numpy.frombuffer(bytes(s),numpy.uint32)
                   # Hard wired Unsigned Int32
                   print(d.shape)
                   print(d[0:10],d[int(d.shape[0]/2)],d[len(d)-1])
                   print(d[int(d.shape[0]/3):int(d.shape[0]/3+20)])
                   d=numpy.reshape(d,(2300,2300))
#                   from matplotlib import pylab
#                   pylab.imshow(d,vmin=0,vmax=1000)
#                   pylab.show()
                except ImportError:
                   print("You need to get numpy and matplotlib to see the data")
            else:
                value=object.get_value()
                print("Val:",value,i)
    print()
del(object)
#
print(dir())
#object.free_handle(handle)
