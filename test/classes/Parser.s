Classfile /Users/didi/workspace/jvm/my_jvm/class_parser/test/classes/Parser.class
  Last modified 2019-1-14; size 6724 bytes
  MD5 checksum 732f7c2c39bd8022e9a437133b11b1a9
  Compiled from "Parser.java"
public class bencode.parse.Parser
  minor version: 0
  major version: 52
  flags: ACC_PUBLIC, ACC_SUPER
Constant pool:
    #1 = Class              #2            // bencode/parse/Parser
    #2 = Utf8               bencode/parse/Parser
    #3 = Class              #4            // java/lang/Object
    #4 = Utf8               java/lang/Object
    #5 = Utf8               logger
    #6 = Utf8               Lorg/slf4j/Logger;
    #7 = Utf8               <clinit>
    #8 = Utf8               ()V
    #9 = Utf8               Code
   #10 = Methodref          #11.#13       // org/slf4j/LoggerFactory.getLogger:(Ljava/lang/Class;)Lorg/slf4j/Logger;
   #11 = Class              #12           // org/slf4j/LoggerFactory
   #12 = Utf8               org/slf4j/LoggerFactory
   #13 = NameAndType        #14:#15       // getLogger:(Ljava/lang/Class;)Lorg/slf4j/Logger;
   #14 = Utf8               getLogger
   #15 = Utf8               (Ljava/lang/Class;)Lorg/slf4j/Logger;
   #16 = Fieldref           #1.#17        // bencode/parse/Parser.logger:Lorg/slf4j/Logger;
   #17 = NameAndType        #5:#6         // logger:Lorg/slf4j/Logger;
   #18 = Utf8               LineNumberTable
   #19 = Utf8               LocalVariableTable
   #20 = Utf8               <init>
   #21 = Methodref          #3.#22        // java/lang/Object."<init>":()V
   #22 = NameAndType        #20:#8        // "<init>":()V
   #23 = Utf8               this
   #24 = Utf8               Lbencode/parse/Parser;
   #25 = Utf8               parse
   #26 = Utf8               ([BII)Lbencode/type/BList;
   #27 = Class              #28           // bencode/type/BList
   #28 = Utf8               bencode/type/BList
   #29 = Methodref          #27.#22       // bencode/type/BList."<init>":()V
   #30 = Methodref          #1.#31        // bencode/parse/Parser.parseNext:([BI)Lbencode/type/BType;
   #31 = NameAndType        #32:#33       // parseNext:([BI)Lbencode/type/BType;
   #32 = Utf8               parseNext
   #33 = Utf8               ([BI)Lbencode/type/BType;
   #34 = InterfaceMethodref #35.#37       // bencode/type/BType.getContentLength:()I
   #35 = Class              #36           // bencode/type/BType
   #36 = Utf8               bencode/type/BType
   #37 = NameAndType        #38:#39       // getContentLength:()I
   #38 = Utf8               getContentLength
   #39 = Utf8               ()I
   #40 = Methodref          #27.#41       // bencode/type/BList.add:(Lbencode/type/BType;)V
   #41 = NameAndType        #42:#43       // add:(Lbencode/type/BType;)V
   #42 = Utf8               add
   #43 = Utf8               (Lbencode/type/BType;)V
   #44 = Utf8               content
   #45 = Utf8               [B
   #46 = Utf8               offset
   #47 = Utf8               I
   #48 = Utf8               parseLength
   #49 = Utf8               result
   #50 = Utf8               Lbencode/type/BList;
   #51 = Utf8               i
   #52 = Utf8               element
   #53 = Utf8               Lbencode/type/BType;
   #54 = Utf8               LocalVariableTypeTable
   #55 = Utf8               Lbencode/type/BType<*>;
   #56 = Utf8               StackMapTable
   #57 = Utf8               Signature
   #58 = Utf8               ([BI)Lbencode/type/BType<*>;
   #59 = Methodref          #1.#60        // bencode/parse/Parser.parseNumber:([BI)Lbencode/type/BNumber;
   #60 = NameAndType        #61:#62       // parseNumber:([BI)Lbencode/type/BNumber;
   #61 = Utf8               parseNumber
   #62 = Utf8               ([BI)Lbencode/type/BNumber;
   #63 = Methodref          #1.#64        // bencode/parse/Parser.parseList:([BI)Lbencode/type/BList;
   #64 = NameAndType        #65:#66       // parseList:([BI)Lbencode/type/BList;
   #65 = Utf8               parseList
   #66 = Utf8               ([BI)Lbencode/type/BList;
   #67 = Methodref          #1.#68        // bencode/parse/Parser.parseDic:([BI)Lbencode/type/BDictionary;
   #68 = NameAndType        #69:#70       // parseDic:([BI)Lbencode/type/BDictionary;
   #69 = Utf8               parseDic
   #70 = Utf8               ([BI)Lbencode/type/BDictionary;
   #71 = Methodref          #1.#72        // bencode/parse/Parser.parseString:([BI)Lbencode/type/BString;
   #72 = NameAndType        #73:#74       // parseString:([BI)Lbencode/type/BString;
   #73 = Utf8               parseString
   #74 = Utf8               ([BI)Lbencode/type/BString;
   #75 = String             #76           // Unexpected char in bencode when detemining bencode type, char = {}, pos = {}
   #76 = Utf8               Unexpected char in bencode when detemining bencode type, char = {}, pos = {}
   #77 = Methodref          #78.#80       // java/lang/Byte.valueOf:(B)Ljava/lang/Byte;
   #78 = Class              #79           // java/lang/Byte
   #79 = Utf8               java/lang/Byte
   #80 = NameAndType        #81:#82       // valueOf:(B)Ljava/lang/Byte;
   #81 = Utf8               valueOf
   #82 = Utf8               (B)Ljava/lang/Byte;
   #83 = Methodref          #84.#86       // java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
   #84 = Class              #85           // java/lang/Integer
   #85 = Utf8               java/lang/Integer
   #86 = NameAndType        #81:#87       // valueOf:(I)Ljava/lang/Integer;
   #87 = Utf8               (I)Ljava/lang/Integer;
   #88 = InterfaceMethodref #89.#91       // org/slf4j/Logger.error:(Ljava/lang/String;Ljava/lang/Object;Ljava/lang/Object;)V
   #89 = Class              #90           // org/slf4j/Logger
   #90 = Utf8               org/slf4j/Logger
   #91 = NameAndType        #92:#93       // error:(Ljava/lang/String;Ljava/lang/Object;Ljava/lang/Object;)V
   #92 = Utf8               error
   #93 = Utf8               (Ljava/lang/String;Ljava/lang/Object;Ljava/lang/Object;)V
   #94 = Class              #95           // bencode/exception/BEncodeFormatException
   #95 = Utf8               bencode/exception/BEncodeFormatException
   #96 = Class              #97           // java/lang/StringBuilder
   #97 = Utf8               java/lang/StringBuilder
   #98 = String             #99           // Unexpected char in bencode, when detemining bencode type, char =
   #99 = Utf8               Unexpected char in bencode, when detemining bencode type, char =
  #100 = Methodref          #96.#101      // java/lang/StringBuilder."<init>":(Ljava/lang/String;)V
  #101 = NameAndType        #20:#102      // "<init>":(Ljava/lang/String;)V
  #102 = Utf8               (Ljava/lang/String;)V
  #103 = Methodref          #96.#104      // java/lang/StringBuilder.append:(C)Ljava/lang/StringBuilder;
  #104 = NameAndType        #105:#106     // append:(C)Ljava/lang/StringBuilder;
  #105 = Utf8               append
  #106 = Utf8               (C)Ljava/lang/StringBuilder;
  #107 = String             #108          // , pos =
  #108 = Utf8               , pos =
  #109 = Methodref          #96.#110      // java/lang/StringBuilder.append:(Ljava/lang/String;)Ljava/lang/StringBuilder;
  #110 = NameAndType        #105:#111     // append:(Ljava/lang/String;)Ljava/lang/StringBuilder;
  #111 = Utf8               (Ljava/lang/String;)Ljava/lang/StringBuilder;
  #112 = Methodref          #96.#113      // java/lang/StringBuilder.append:(I)Ljava/lang/StringBuilder;
  #113 = NameAndType        #105:#114     // append:(I)Ljava/lang/StringBuilder;
  #114 = Utf8               (I)Ljava/lang/StringBuilder;
  #115 = Methodref          #96.#116      // java/lang/StringBuilder.toString:()Ljava/lang/String;
  #116 = NameAndType        #117:#118     // toString:()Ljava/lang/String;
  #117 = Utf8               toString
  #118 = Utf8               ()Ljava/lang/String;
  #119 = Methodref          #94.#101      // bencode/exception/BEncodeFormatException."<init>":(Ljava/lang/String;)V
  #120 = Utf8               current
  #121 = Utf8               B
  #122 = String             #123          // Parsing number unfinished when reaching the end, starting pos = {}
  #123 = Utf8               Parsing number unfinished when reaching the end, starting pos = {}
  #124 = InterfaceMethodref #89.#125      // org/slf4j/Logger.error:(Ljava/lang/String;Ljava/lang/Object;)V
  #125 = NameAndType        #92:#126      // error:(Ljava/lang/String;Ljava/lang/Object;)V
  #126 = Utf8               (Ljava/lang/String;Ljava/lang/Object;)V
  #127 = String             #128          // Parsing number unfinished when reaching the end, starting pos =
  #128 = Utf8               Parsing number unfinished when reaching the end, starting pos =
  #129 = String             #130          // Numbers not found when parsing number, pos = {}
  #130 = Utf8               Numbers not found when parsing number, pos = {}
  #131 = String             #132          // Numbers not found when parsing number, pos =
  #132 = Utf8               Numbers not found when parsing number, pos =
  #133 = Class              #134          // bencode/type/BNumber
  #134 = Utf8               bencode/type/BNumber
  #135 = Methodref          #133.#22      // bencode/type/BNumber."<init>":()V
  #136 = String             #137          // Find invalid nagetive-zero when parsing number, pos = {}
  #137 = Utf8               Find invalid nagetive-zero when parsing number, pos = {}
  #138 = String             #139          // Find invalid nagetive-zero when parsing number, pos =
  #139 = Utf8               Find invalid nagetive-zero when parsing number, pos =
  #140 = Long               -1l
  #142 = Methodref          #143.#145     // java/lang/Long.valueOf:(J)Ljava/lang/Long;
  #143 = Class              #144          // java/lang/Long
  #144 = Utf8               java/lang/Long
  #145 = NameAndType        #81:#146      // valueOf:(J)Ljava/lang/Long;
  #146 = Utf8               (J)Ljava/lang/Long;
  #147 = Methodref          #133.#148     // bencode/type/BNumber.setContent:(Ljava/lang/Long;)V
  #148 = NameAndType        #149:#150     // setContent:(Ljava/lang/Long;)V
  #149 = Utf8               setContent
  #150 = Utf8               (Ljava/lang/Long;)V
  #151 = String             #152          // Find unexpected pre-zero when parsing number, pos = {}
  #152 = Utf8               Find unexpected pre-zero when parsing number, pos = {}
  #153 = String             #154          // Find unexpected pre-zero when parsing number, pos =
  #154 = Utf8               Find unexpected pre-zero when parsing number, pos =
  #155 = Long               10l
  #157 = String             #158          // Parsing number unfinished when reaching the end, starting post =
  #158 = Utf8               Parsing number unfinished when reaching the end, starting post =
  #159 = String             #160          // Parsing value, pos = {}, type = {}, value = {}, length = {}
  #160 = Utf8               Parsing value, pos = {}, type = {}, value = {}, length = {}
  #161 = Methodref          #133.#162     // bencode/type/BNumber.getContent:()Ljava/lang/Long;
  #162 = NameAndType        #163:#164     // getContent:()Ljava/lang/Long;
  #163 = Utf8               getContent
  #164 = Utf8               ()Ljava/lang/Long;
  #165 = Methodref          #133.#37      // bencode/type/BNumber.getContentLength:()I
  #166 = InterfaceMethodref #89.#167      // org/slf4j/Logger.debug:(Ljava/lang/String;[Ljava/lang/Object;)V
  #167 = NameAndType        #168:#169     // debug:(Ljava/lang/String;[Ljava/lang/Object;)V
  #168 = Utf8               debug
  #169 = Utf8               (Ljava/lang/String;[Ljava/lang/Object;)V
  #170 = Utf8               pin
  #171 = Utf8               contentLength
  #172 = Utf8               isNagetive
  #173 = Utf8               Z
  #174 = Utf8               bInteger
  #175 = Utf8               Lbencode/type/BNumber;
  #176 = Utf8               value
  #177 = Utf8               J
  #178 = Class              #45           // "[B"
  #179 = String             #180          // Parsing string unfinished when reaching the end, starting pos = {}
  #180 = Utf8               Parsing string unfinished when reaching the end, starting pos = {}
  #181 = String             #182          // Parsing string unfinished when reaching the end, starting pos =
  #182 = Utf8               Parsing string unfinished when reaching the end, starting pos =
  #183 = Class              #184          // bencode/type/BString
  #184 = Utf8               bencode/type/BString
  #185 = Methodref          #183.#22      // bencode/type/BString."<init>":()V
  #186 = Methodref          #187.#189     // java/util/Arrays.copyOfRange:([BII)[B
  #187 = Class              #188          // java/util/Arrays
  #188 = Utf8               java/util/Arrays
  #189 = NameAndType        #190:#191     // copyOfRange:([BII)[B
  #190 = Utf8               copyOfRange
  #191 = Utf8               ([BII)[B
  #192 = Methodref          #183.#193     // bencode/type/BString.setContent:([B)V
  #193 = NameAndType        #149:#194     // setContent:([B)V
  #194 = Utf8               ([B)V
  #195 = Methodref          #183.#196     // bencode/type/BString.getContent:()[B
  #196 = NameAndType        #163:#197     // getContent:()[B
  #197 = Utf8               ()[B
  #198 = Methodref          #183.#37      // bencode/type/BString.getContentLength:()I
  #199 = Utf8               bString
  #200 = Utf8               Lbencode/type/BString;
  #201 = String             #202          // Parsing list unfinished when reaching the end, starting pos = {}
  #202 = Utf8               Parsing list unfinished when reaching the end, starting pos = {}
  #203 = Methodref          #27.#204      // bencode/type/BList.getContent:()Ljava/util/LinkedList;
  #204 = NameAndType        #163:#205     // getContent:()Ljava/util/LinkedList;
  #205 = Utf8               ()Ljava/util/LinkedList;
  #206 = Methodref          #27.#37       // bencode/type/BList.getContentLength:()I
  #207 = Utf8               bList
  #208 = Utf8               bElement
  #209 = Class              #210          // bencode/type/BDictionary
  #210 = Utf8               bencode/type/BDictionary
  #211 = Methodref          #209.#22      // bencode/type/BDictionary."<init>":()V
  #212 = String             #213          // Parsing dictionary unfinished when reaching the end, starting pos = {}
  #213 = Utf8               Parsing dictionary unfinished when reaching the end, starting pos = {}
  #214 = String             #215          // Parsing dictionary unfinished when reaching the end, starting pos =
  #215 = Utf8               Parsing dictionary unfinished when reaching the end, starting pos =
  #216 = Methodref          #209.#217     // bencode/type/BDictionary.put:(Lbencode/type/BString;Lbencode/type/BType;)Lbencode/type/BType;
  #217 = NameAndType        #218:#219     // put:(Lbencode/type/BString;Lbencode/type/BType;)Lbencode/type/BType;
  #218 = Utf8               put
  #219 = Utf8               (Lbencode/type/BString;Lbencode/type/BType;)Lbencode/type/BType;
  #220 = Methodref          #209.#221     // bencode/type/BDictionary.getContent:()Ljava/util/TreeMap;
  #221 = NameAndType        #163:#222     // getContent:()Ljava/util/TreeMap;
  #222 = Utf8               ()Ljava/util/TreeMap;
  #223 = Methodref          #209.#37      // bencode/type/BDictionary.getContentLength:()I
  #224 = Utf8               bDictionary
  #225 = Utf8               Lbencode/type/BDictionary;
  #226 = Utf8               key
  #227 = Utf8               SourceFile
  #228 = Utf8               Parser.java
{
  static {};
    descriptor: ()V
    flags: ACC_STATIC
    Code:
      stack=1, locals=0, args_size=0
         0: ldc           #1                  // class bencode/parse/Parser
         2: invokestatic  #10                 // Method org/slf4j/LoggerFactory.getLogger:(Ljava/lang/Class;)Lorg/slf4j/Logger;
         5: putstatic     #16                 // Field logger:Lorg/slf4j/Logger;
         8: return
      LineNumberTable:
        line 24: 0
      LocalVariableTable:
        Start  Length  Slot  Name   Signature

  public bencode.parse.Parser();
    descriptor: ()V
    flags: ACC_PUBLIC
    Code:
      stack=1, locals=1, args_size=1
         0: aload_0
         1: invokespecial #21                 // Method java/lang/Object."<init>":()V
         4: return
      LineNumberTable:
        line 22: 0
      LocalVariableTable:
        Start  Length  Slot  Name   Signature
            0       5     0  this   Lbencode/parse/Parser;

  public bencode.type.BList parse(byte[], int, int);
    descriptor: ([BII)Lbencode/type/BList;
    flags: ACC_PUBLIC
    Code:
      stack=3, locals=7, args_size=4
         0: new           #27                 // class bencode/type/BList
         3: dup
         4: invokespecial #29                 // Method bencode/type/BList."<init>":()V
         7: astore        4
         9: iload_2
        10: istore        5
        12: goto          43
        15: aload_0
        16: aload_1
        17: iload         5
        19: invokespecial #30                 // Method parseNext:([BI)Lbencode/type/BType;
        22: astore        6
        24: iload         5
        26: aload         6
        28: invokeinterface #34,  1           // InterfaceMethod bencode/type/BType.getContentLength:()I
        33: iadd
        34: istore        5
        36: aload         4
        38: aload         6
        40: invokevirtual #40                 // Method bencode/type/BList.add:(Lbencode/type/BType;)V
        43: iload         5
        45: iload_3
        46: if_icmplt     15
        49: aload         4
        51: areturn
      LineNumberTable:
        line 36: 0
        line 37: 9
        line 38: 15
        line 39: 24
        line 40: 36
        line 37: 43
        line 42: 49
      LocalVariableTable:
        Start  Length  Slot  Name   Signature
            0      52     0  this   Lbencode/parse/Parser;
            0      52     1 content   [B
            0      52     2 offset   I
            0      52     3 parseLength   I
            9      43     4 result   Lbencode/type/BList;
           12      37     5     i   I
           24      19     6 element   Lbencode/type/BType;
      LocalVariableTypeTable:
        Start  Length  Slot  Name   Signature
           24      19     6 element   Lbencode/type/BType<*>;
      StackMapTable: number_of_entries = 2
        frame_type = 253 /* append */
          offset_delta = 15
          locals = [ class bencode/type/BList, int ]
        frame_type = 27 /* same */

  public bencode.type.BNumber parseNumber(byte[], int);
    descriptor: ([BI)Lbencode/type/BNumber;
    flags: ACC_PUBLIC
    Code:
      stack=6, locals=11, args_size=3
         0: iload_2
         1: iconst_1
         2: iadd
         3: istore_3
         4: iload_3
         5: istore        4
         7: aload_1
         8: arraylength
         9: istore        5
        11: iconst_0
        12: istore        6
        14: iload_3
        15: iload         5
        17: if_icmplt     58
        20: getstatic     #16                 // Field logger:Lorg/slf4j/Logger;
        23: ldc           #122                // String Parsing number unfinished when reaching the end, starting pos = {}
        25: iload_2
        26: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
        29: invokeinterface #124,  3          // InterfaceMethod org/slf4j/Logger.error:(Ljava/lang/String;Ljava/lang/Object;)V
        34: new           #94                 // class bencode/exception/BEncodeFormatException
        37: dup
        38: new           #96                 // class java/lang/StringBuilder
        41: dup
        42: ldc           #127                // String Parsing number unfinished when reaching the end, starting pos =
        44: invokespecial #100                // Method java/lang/StringBuilder."<init>":(Ljava/lang/String;)V
        47: iload_2
        48: invokevirtual #112                // Method java/lang/StringBuilder.append:(I)Ljava/lang/StringBuilder;
        51: invokevirtual #115                // Method java/lang/StringBuilder.toString:()Ljava/lang/String;
        54: invokespecial #119                // Method bencode/exception/BEncodeFormatException."<init>":(Ljava/lang/String;)V
        57: athrow
        58: bipush        45
        60: aload_1
        61: iload_3
        62: baload
        63: if_icmpne     72
        66: iconst_1
        67: istore        6
        69: iinc          3, 1
        72: bipush        101
        74: aload_1
        75: iload_3
        76: baload
        77: if_icmpne     118
        80: getstatic     #16                 // Field logger:Lorg/slf4j/Logger;
        83: ldc           #129                // String Numbers not found when parsing number, pos = {}
        85: iload_3
        86: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
        89: invokeinterface #124,  3          // InterfaceMethod org/slf4j/Logger.error:(Ljava/lang/String;Ljava/lang/Object;)V
        94: new           #94                 // class bencode/exception/BEncodeFormatException
        97: dup
        98: new           #96                 // class java/lang/StringBuilder
       101: dup
       102: ldc           #131                // String Numbers not found when parsing number, pos =
       104: invokespecial #100                // Method java/lang/StringBuilder."<init>":(Ljava/lang/String;)V
       107: iload_3
       108: invokevirtual #112                // Method java/lang/StringBuilder.append:(I)Ljava/lang/StringBuilder;
       111: invokevirtual #115                // Method java/lang/StringBuilder.toString:()Ljava/lang/String;
       114: invokespecial #119                // Method bencode/exception/BEncodeFormatException."<init>":(Ljava/lang/String;)V
       117: athrow
       118: aconst_null
       119: astore        7
       121: lconst_0
       122: lstore        8
       124: aload_1
       125: iload_3
       126: baload
       127: istore        10
       129: bipush        101
       131: iload         10
       133: if_icmpne     216
       136: new           #133                // class bencode/type/BNumber
       139: dup
       140: invokespecial #135                // Method bencode/type/BNumber."<init>":()V
       143: astore        7
       145: iload         6
       147: ifeq          203
       150: lconst_0
       151: lload         8
       153: lcmp
       154: ifne          195
       157: getstatic     #16                 // Field logger:Lorg/slf4j/Logger;
       160: ldc           #136                // String Find invalid nagetive-zero when parsing number, pos = {}
       162: iload_3
       163: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
       166: invokeinterface #124,  3          // InterfaceMethod org/slf4j/Logger.error:(Ljava/lang/String;Ljava/lang/Object;)V
       171: new           #94                 // class bencode/exception/BEncodeFormatException
       174: dup
       175: new           #96                 // class java/lang/StringBuilder
       178: dup
       179: ldc           #138                // String Find invalid nagetive-zero when parsing number, pos =
       181: invokespecial #100                // Method java/lang/StringBuilder."<init>":(Ljava/lang/String;)V
       184: iload_3
       185: invokevirtual #112                // Method java/lang/StringBuilder.append:(I)Ljava/lang/StringBuilder;
       188: invokevirtual #115                // Method java/lang/StringBuilder.toString:()Ljava/lang/String;
       191: invokespecial #119                // Method bencode/exception/BEncodeFormatException."<init>":(Ljava/lang/String;)V
       194: athrow
       195: lload         8
       197: ldc2_w        #140                // long -1l
       200: lmul
       201: lstore        8
       203: aload         7
       205: lload         8
       207: invokestatic  #142                // Method java/lang/Long.valueOf:(J)Ljava/lang/Long;
       210: invokevirtual #147                // Method bencode/type/BNumber.setContent:(Ljava/lang/Long;)V
       213: goto          307
       216: iload_3
       217: iload         4
       219: if_icmpne     283
       222: bipush        48
       224: iload         10
       226: if_icmpne     283
       229: iload_3
       230: iload         5
       232: if_icmpge     283
       235: bipush        101
       237: aload_1
       238: iload_3
       239: iconst_1
       240: iadd
       241: baload
       242: if_icmpeq     283
       245: getstatic     #16                 // Field logger:Lorg/slf4j/Logger;
       248: ldc           #151                // String Find unexpected pre-zero when parsing number, pos = {}
       250: iload_3
       251: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
       254: invokeinterface #124,  3          // InterfaceMethod org/slf4j/Logger.error:(Ljava/lang/String;Ljava/lang/Object;)V
       259: new           #94                 // class bencode/exception/BEncodeFormatException
       262: dup
       263: new           #96                 // class java/lang/StringBuilder
       266: dup
       267: ldc           #153                // String Find unexpected pre-zero when parsing number, pos =
       269: invokespecial #100                // Method java/lang/StringBuilder."<init>":(Ljava/lang/String;)V
       272: iload_3
       273: invokevirtual #112                // Method java/lang/StringBuilder.append:(I)Ljava/lang/StringBuilder;
       276: invokevirtual #115                // Method java/lang/StringBuilder.toString:()Ljava/lang/String;
       279: invokespecial #119                // Method bencode/exception/BEncodeFormatException."<init>":(Ljava/lang/String;)V
       282: athrow
       283: lload         8
       285: ldc2_w        #155                // long 10l
       288: lmul
       289: iload         10
       291: bipush        48
       293: isub
       294: i2l
       295: ladd
       296: lstore        8
       298: iinc          3, 1
       301: iload_3
       302: iload         5
       304: if_icmplt     124
       307: aload         7
       309: ifnonnull     350
       312: getstatic     #16                 // Field logger:Lorg/slf4j/Logger;
       315: ldc           #122                // String Parsing number unfinished when reaching the end, starting pos = {}
       317: iload_2
       318: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
       321: invokeinterface #124,  3          // InterfaceMethod org/slf4j/Logger.error:(Ljava/lang/String;Ljava/lang/Object;)V
       326: new           #94                 // class bencode/exception/BEncodeFormatException
       329: dup
       330: new           #96                 // class java/lang/StringBuilder
       333: dup
       334: ldc           #157                // String Parsing number unfinished when reaching the end, starting post =
       336: invokespecial #100                // Method java/lang/StringBuilder."<init>":(Ljava/lang/String;)V
       339: iload_2
       340: invokevirtual #112                // Method java/lang/StringBuilder.append:(I)Ljava/lang/StringBuilder;
       343: invokevirtual #115                // Method java/lang/StringBuilder.toString:()Ljava/lang/String;
       346: invokespecial #119                // Method bencode/exception/BEncodeFormatException."<init>":(Ljava/lang/String;)V
       349: athrow
       350: getstatic     #16                 // Field logger:Lorg/slf4j/Logger;
       353: ldc           #159                // String Parsing value, pos = {}, type = {}, value = {}, length = {}
       355: iconst_4
       356: anewarray     #3                  // class java/lang/Object
       359: dup
       360: iconst_0
       361: iload_2
       362: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
       365: aastore
       366: dup
       367: iconst_1
       368: ldc           #133                // class bencode/type/BNumber
       370: aastore
       371: dup
       372: iconst_2
       373: aload         7
       375: invokevirtual #161                // Method bencode/type/BNumber.getContent:()Ljava/lang/Long;
       378: aastore
       379: dup
       380: iconst_3
       381: aload         7
       383: invokevirtual #165                // Method bencode/type/BNumber.getContentLength:()I
       386: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
       389: aastore
       390: invokeinterface #166,  3          // InterfaceMethod org/slf4j/Logger.debug:(Ljava/lang/String;[Ljava/lang/Object;)V
       395: aload         7
       397: areturn
      LineNumberTable:
        line 111: 0
        line 112: 7
        line 113: 11
        line 115: 14
        line 116: 20
        line 117: 23
        line 118: 25
        line 116: 29
        line 119: 34
        line 120: 38
        line 121: 47
        line 120: 51
        line 119: 54
        line 124: 58
        line 125: 66
        line 126: 69
        line 129: 72
        line 130: 80
        line 131: 94
        line 132: 98
        line 131: 114
        line 135: 118
        line 136: 121
        line 138: 124
        line 139: 129
        line 140: 136
        line 141: 145
        line 142: 150
        line 143: 157
        line 144: 160
        line 143: 166
        line 145: 171
        line 146: 175
        line 145: 191
        line 148: 195
        line 151: 203
        line 152: 213
        line 154: 216
        line 155: 229
        line 156: 245
        line 157: 248
        line 156: 254
        line 158: 259
        line 159: 263
        line 158: 279
        line 161: 283
        line 164: 298
        line 165: 301
        line 137: 304
        line 167: 307
        line 168: 312
        line 169: 315
        line 170: 317
        line 168: 321
        line 171: 326
        line 172: 330
        line 173: 339
        line 172: 343
        line 171: 346
        line 176: 350
        line 177: 353
        line 178: 361
        line 179: 373
        line 176: 390
        line 181: 395
      LocalVariableTable:
        Start  Length  Slot  Name   Signature
            0     398     0  this   Lbencode/parse/Parser;
            0     398     1 content   [B
            0     398     2 offset   I
            4     394     3     i   I
            7     391     4   pin   I
           11     387     5 contentLength   I
           14     384     6 isNagetive   Z
          121     277     7 bInteger   Lbencode/type/BNumber;
          124     274     8 value   J
          129     172    10 current   B
      StackMapTable: number_of_entries = 10
        frame_type = 255 /* full_frame */
          offset_delta = 58
          locals = [ class bencode/parse/Parser, class "[B", int, int, int, int, int ]
          stack = []
        frame_type = 13 /* same */
        frame_type = 45 /* same */
        frame_type = 253 /* append */
          offset_delta = 5
          locals = [ class bencode/type/BNumber, long ]
        frame_type = 252 /* append */
          offset_delta = 70
          locals = [ int ]
        frame_type = 7 /* same */
        frame_type = 12 /* same */
        frame_type = 251 /* same_frame_extended */
          offset_delta = 66
        frame_type = 250 /* chop */
          offset_delta = 23
        frame_type = 42 /* same */

  public bencode.type.BString parseString(byte[], int);
    descriptor: ([BI)Lbencode/type/BString;
    flags: ACC_PUBLIC
    Code:
      stack=6, locals=8, args_size=3
         0: iload_2
         1: istore_3
         2: iconst_0
         3: istore        4
         5: aload_1
         6: arraylength
         7: istore        5
         9: aconst_null
        10: astore        6
        12: aload_1
        13: iload_3
        14: iinc          3, 1
        17: baload
        18: istore        7
        20: bipush        58
        22: iload         7
        24: if_icmpeq     43
        27: iload         4
        29: bipush        10
        31: imul
        32: iload         7
        34: bipush        48
        36: isub
        37: iadd
        38: istore        4
        40: goto          118
        43: iload         5
        45: iload_3
        46: isub
        47: iconst_1
        48: iadd
        49: iload         4
        51: if_icmpge     92
        54: getstatic     #16                 // Field logger:Lorg/slf4j/Logger;
        57: ldc           #179                // String Parsing string unfinished when reaching the end, starting pos = {}
        59: iload_2
        60: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
        63: invokeinterface #124,  3          // InterfaceMethod org/slf4j/Logger.error:(Ljava/lang/String;Ljava/lang/Object;)V
        68: new           #94                 // class bencode/exception/BEncodeFormatException
        71: dup
        72: new           #96                 // class java/lang/StringBuilder
        75: dup
        76: ldc           #181                // String Parsing string unfinished when reaching the end, starting pos =
        78: invokespecial #100                // Method java/lang/StringBuilder."<init>":(Ljava/lang/String;)V
        81: iload_2
        82: invokevirtual #112                // Method java/lang/StringBuilder.append:(I)Ljava/lang/StringBuilder;
        85: invokevirtual #115                // Method java/lang/StringBuilder.toString:()Ljava/lang/String;
        88: invokespecial #119                // Method bencode/exception/BEncodeFormatException."<init>":(Ljava/lang/String;)V
        91: athrow
        92: new           #183                // class bencode/type/BString
        95: dup
        96: invokespecial #185                // Method bencode/type/BString."<init>":()V
        99: astore        6
       101: aload         6
       103: aload_1
       104: iload_3
       105: iload_3
       106: iload         4
       108: iadd
       109: invokestatic  #186                // Method java/util/Arrays.copyOfRange:([BII)[B
       112: invokevirtual #192                // Method bencode/type/BString.setContent:([B)V
       115: goto          124
       118: iload_3
       119: iload         5
       121: if_icmplt     12
       124: aload         6
       126: ifnonnull     167
       129: getstatic     #16                 // Field logger:Lorg/slf4j/Logger;
       132: ldc           #179                // String Parsing string unfinished when reaching the end, starting pos = {}
       134: iload_2
       135: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
       138: invokeinterface #124,  3          // InterfaceMethod org/slf4j/Logger.error:(Ljava/lang/String;Ljava/lang/Object;)V
       143: new           #94                 // class bencode/exception/BEncodeFormatException
       146: dup
       147: new           #96                 // class java/lang/StringBuilder
       150: dup
       151: ldc           #181                // String Parsing string unfinished when reaching the end, starting pos =
       153: invokespecial #100                // Method java/lang/StringBuilder."<init>":(Ljava/lang/String;)V
       156: iload_2
       157: invokevirtual #112                // Method java/lang/StringBuilder.append:(I)Ljava/lang/StringBuilder;
       160: invokevirtual #115                // Method java/lang/StringBuilder.toString:()Ljava/lang/String;
       163: invokespecial #119                // Method bencode/exception/BEncodeFormatException."<init>":(Ljava/lang/String;)V
       166: athrow
       167: getstatic     #16                 // Field logger:Lorg/slf4j/Logger;
       170: ldc           #159                // String Parsing value, pos = {}, type = {}, value = {}, length = {}
       172: iconst_4
       173: anewarray     #3                  // class java/lang/Object
       176: dup
       177: iconst_0
       178: iload_2
       179: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
       182: aastore
       183: dup
       184: iconst_1
       185: ldc           #183                // class bencode/type/BString
       187: aastore
       188: dup
       189: iconst_2
       190: aload         6
       192: invokevirtual #195                // Method bencode/type/BString.getContent:()[B
       195: aastore
       196: dup
       197: iconst_3
       198: aload         6
       200: invokevirtual #198                // Method bencode/type/BString.getContentLength:()I
       203: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
       206: aastore
       207: invokeinterface #166,  3          // InterfaceMethod org/slf4j/Logger.debug:(Ljava/lang/String;[Ljava/lang/Object;)V
       212: aload         6
       214: areturn
      LineNumberTable:
        line 192: 0
        line 193: 2
        line 194: 5
        line 196: 9
        line 198: 12
        line 199: 20
        line 200: 27
        line 201: 40
        line 202: 43
        line 203: 54
        line 204: 57
        line 206: 59
        line 203: 63
        line 207: 68
        line 208: 72
        line 209: 81
        line 208: 85
        line 207: 88
        line 211: 92
        line 212: 101
        line 213: 115
        line 215: 118
        line 197: 121
        line 217: 124
        line 218: 129
        line 219: 132
        line 221: 134
        line 218: 138
        line 222: 143
        line 223: 147
        line 224: 156
        line 223: 160
        line 222: 163
        line 227: 167
        line 228: 170
        line 229: 178
        line 230: 190
        line 227: 207
        line 232: 212
      LocalVariableTable:
        Start  Length  Slot  Name   Signature
            0     215     0  this   Lbencode/parse/Parser;
            0     215     1 content   [B
            0     215     2 offset   I
            2     213     3     i   I
            5     210     4 value   I
            9     206     5 contentLength   I
           12     203     6 bString   Lbencode/type/BString;
           20      98     7 current   B
      StackMapTable: number_of_entries = 6
        frame_type = 255 /* full_frame */
          offset_delta = 12
          locals = [ class bencode/parse/Parser, class "[B", int, int, int, int, class bencode/type/BString ]
          stack = []
        frame_type = 252 /* append */
          offset_delta = 30
          locals = [ int ]
        frame_type = 48 /* same */
        frame_type = 250 /* chop */
          offset_delta = 25
        frame_type = 5 /* same */
        frame_type = 42 /* same */

  public bencode.type.BList parseList(byte[], int);
    descriptor: ([BI)Lbencode/type/BList;
    flags: ACC_PUBLIC
    Code:
      stack=6, locals=7, args_size=3
         0: new           #27                 // class bencode/type/BList
         3: dup
         4: invokespecial #29                 // Method bencode/type/BList."<init>":()V
         7: astore_3
         8: iload_2
         9: iconst_1
        10: iadd
        11: istore        4
        13: aload_1
        14: arraylength
        15: istore        5
        17: iload         4
        19: iload         5
        21: if_icmplt     62
        24: getstatic     #16                 // Field logger:Lorg/slf4j/Logger;
        27: ldc           #201                // String Parsing list unfinished when reaching the end, starting pos = {}
        29: iload_2
        30: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
        33: invokeinterface #124,  3          // InterfaceMethod org/slf4j/Logger.error:(Ljava/lang/String;Ljava/lang/Object;)V
        38: new           #94                 // class bencode/exception/BEncodeFormatException
        41: dup
        42: new           #96                 // class java/lang/StringBuilder
        45: dup
        46: ldc           #181                // String Parsing string unfinished when reaching the end, starting pos =
        48: invokespecial #100                // Method java/lang/StringBuilder."<init>":(Ljava/lang/String;)V
        51: iload_2
        52: invokevirtual #112                // Method java/lang/StringBuilder.append:(I)Ljava/lang/StringBuilder;
        55: invokevirtual #115                // Method java/lang/StringBuilder.toString:()Ljava/lang/String;
        58: invokespecial #119                // Method bencode/exception/BEncodeFormatException."<init>":(Ljava/lang/String;)V
        61: athrow
        62: bipush        101
        64: aload_1
        65: iload         4
        67: baload
        68: if_icmpne     73
        71: aload_3
        72: areturn
        73: aload_0
        74: aload_1
        75: iload         4
        77: invokespecial #30                 // Method parseNext:([BI)Lbencode/type/BType;
        80: astore        6
        82: aload_3
        83: aload         6
        85: invokevirtual #40                 // Method bencode/type/BList.add:(Lbencode/type/BType;)V
        88: iload         4
        90: aload         6
        92: invokeinterface #34,  1           // InterfaceMethod bencode/type/BType.getContentLength:()I
        97: iadd
        98: istore        4
       100: iload         4
       102: iload         5
       104: if_icmplt     145
       107: getstatic     #16                 // Field logger:Lorg/slf4j/Logger;
       110: ldc           #201                // String Parsing list unfinished when reaching the end, starting pos = {}
       112: iload_2
       113: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
       116: invokeinterface #124,  3          // InterfaceMethod org/slf4j/Logger.error:(Ljava/lang/String;Ljava/lang/Object;)V
       121: new           #94                 // class bencode/exception/BEncodeFormatException
       124: dup
       125: new           #96                 // class java/lang/StringBuilder
       128: dup
       129: ldc           #181                // String Parsing string unfinished when reaching the end, starting pos =
       131: invokespecial #100                // Method java/lang/StringBuilder."<init>":(Ljava/lang/String;)V
       134: iload_2
       135: invokevirtual #112                // Method java/lang/StringBuilder.append:(I)Ljava/lang/StringBuilder;
       138: invokevirtual #115                // Method java/lang/StringBuilder.toString:()Ljava/lang/String;
       141: invokespecial #119                // Method bencode/exception/BEncodeFormatException."<init>":(Ljava/lang/String;)V
       144: athrow
       145: aload_1
       146: iload         4
       148: baload
       149: bipush        101
       151: if_icmpne     73
       154: getstatic     #16                 // Field logger:Lorg/slf4j/Logger;
       157: ldc           #159                // String Parsing value, pos = {}, type = {}, value = {}, length = {}
       159: iconst_4
       160: anewarray     #3                  // class java/lang/Object
       163: dup
       164: iconst_0
       165: iload_2
       166: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
       169: aastore
       170: dup
       171: iconst_1
       172: ldc           #27                 // class bencode/type/BList
       174: aastore
       175: dup
       176: iconst_2
       177: aload_3
       178: invokevirtual #203                // Method bencode/type/BList.getContent:()Ljava/util/LinkedList;
       181: aastore
       182: dup
       183: iconst_3
       184: aload_3
       185: invokevirtual #206                // Method bencode/type/BList.getContentLength:()I
       188: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
       191: aastore
       192: invokeinterface #166,  3          // InterfaceMethod org/slf4j/Logger.debug:(Ljava/lang/String;[Ljava/lang/Object;)V
       197: aload_3
       198: areturn
      LineNumberTable:
        line 244: 0
        line 245: 8
        line 246: 13
        line 248: 17
        line 249: 24
        line 250: 27
        line 252: 29
        line 249: 33
        line 253: 38
        line 254: 42
        line 255: 51
        line 254: 55
        line 253: 58
        line 258: 62
        line 259: 71
        line 263: 73
        line 264: 82
        line 265: 88
        line 266: 100
        line 267: 107
        line 268: 110
        line 270: 112
        line 267: 116
        line 271: 121
        line 272: 125
        line 273: 134
        line 272: 138
        line 271: 141
        line 274: 145
        line 279: 154
        line 280: 157
        line 281: 165
        line 282: 177
        line 279: 192
        line 284: 197
      LocalVariableTable:
        Start  Length  Slot  Name   Signature
            0     199     0  this   Lbencode/parse/Parser;
            0     199     1 content   [B
            0     199     2 offset   I
            8     191     3 bList   Lbencode/type/BList;
           13     186     4     i   I
           17     182     5 contentLength   I
           82      72     6 bElement   Lbencode/type/BType;
      LocalVariableTypeTable:
        Start  Length  Slot  Name   Signature
           82      72     6 bElement   Lbencode/type/BType<*>;
      StackMapTable: number_of_entries = 3
        frame_type = 254 /* append */
          offset_delta = 62
          locals = [ class bencode/type/BList, int, int ]
        frame_type = 10 /* same */
        frame_type = 252 /* append */
          offset_delta = 71
          locals = [ class bencode/type/BType ]

  public bencode.type.BDictionary parseDic(byte[], int);
    descriptor: ([BI)Lbencode/type/BDictionary;
    flags: ACC_PUBLIC
    Code:
      stack=6, locals=8, args_size=3
         0: new           #209                // class bencode/type/BDictionary
         3: dup
         4: invokespecial #211                // Method bencode/type/BDictionary."<init>":()V
         7: astore_3
         8: iload_2
         9: iconst_1
        10: iadd
        11: istore        4
        13: aload_1
        14: arraylength
        15: istore        5
        17: iload         4
        19: iload         5
        21: if_icmplt     62
        24: getstatic     #16                 // Field logger:Lorg/slf4j/Logger;
        27: ldc           #212                // String Parsing dictionary unfinished when reaching the end, starting pos = {}
        29: iload_2
        30: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
        33: invokeinterface #124,  3          // InterfaceMethod org/slf4j/Logger.error:(Ljava/lang/String;Ljava/lang/Object;)V
        38: new           #94                 // class bencode/exception/BEncodeFormatException
        41: dup
        42: new           #96                 // class java/lang/StringBuilder
        45: dup
        46: ldc           #214                // String Parsing dictionary unfinished when reaching the end, starting pos =
        48: invokespecial #100                // Method java/lang/StringBuilder."<init>":(Ljava/lang/String;)V
        51: iload_2
        52: invokevirtual #112                // Method java/lang/StringBuilder.append:(I)Ljava/lang/StringBuilder;
        55: invokevirtual #115                // Method java/lang/StringBuilder.toString:()Ljava/lang/String;
        58: invokespecial #119                // Method bencode/exception/BEncodeFormatException."<init>":(Ljava/lang/String;)V
        61: athrow
        62: bipush        101
        64: aload_1
        65: iload         4
        67: baload
        68: if_icmpne     73
        71: aload_3
        72: areturn
        73: aload_0
        74: aload_1
        75: iload         4
        77: invokevirtual #71                 // Method parseString:([BI)Lbencode/type/BString;
        80: astore        6
        82: iload         4
        84: aload         6
        86: invokevirtual #198                // Method bencode/type/BString.getContentLength:()I
        89: iadd
        90: istore        4
        92: aload_0
        93: aload_1
        94: iload         4
        96: invokespecial #30                 // Method parseNext:([BI)Lbencode/type/BType;
        99: astore        7
       101: iload         4
       103: aload         7
       105: invokeinterface #34,  1           // InterfaceMethod bencode/type/BType.getContentLength:()I
       110: iadd
       111: istore        4
       113: aload_3
       114: aload         6
       116: aload         7
       118: invokevirtual #216                // Method bencode/type/BDictionary.put:(Lbencode/type/BString;Lbencode/type/BType;)Lbencode/type/BType;
       121: pop
       122: iload         4
       124: iload         5
       126: if_icmplt     167
       129: getstatic     #16                 // Field logger:Lorg/slf4j/Logger;
       132: ldc           #201                // String Parsing list unfinished when reaching the end, starting pos = {}
       134: iload_2
       135: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
       138: invokeinterface #124,  3          // InterfaceMethod org/slf4j/Logger.error:(Ljava/lang/String;Ljava/lang/Object;)V
       143: new           #94                 // class bencode/exception/BEncodeFormatException
       146: dup
       147: new           #96                 // class java/lang/StringBuilder
       150: dup
       151: ldc           #181                // String Parsing string unfinished when reaching the end, starting pos =
       153: invokespecial #100                // Method java/lang/StringBuilder."<init>":(Ljava/lang/String;)V
       156: iload_2
       157: invokevirtual #112                // Method java/lang/StringBuilder.append:(I)Ljava/lang/StringBuilder;
       160: invokevirtual #115                // Method java/lang/StringBuilder.toString:()Ljava/lang/String;
       163: invokespecial #119                // Method bencode/exception/BEncodeFormatException."<init>":(Ljava/lang/String;)V
       166: athrow
       167: aload_1
       168: iload         4
       170: baload
       171: bipush        101
       173: if_icmpne     73
       176: getstatic     #16                 // Field logger:Lorg/slf4j/Logger;
       179: ldc           #159                // String Parsing value, pos = {}, type = {}, value = {}, length = {}
       181: iconst_4
       182: anewarray     #3                  // class java/lang/Object
       185: dup
       186: iconst_0
       187: iload_2
       188: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
       191: aastore
       192: dup
       193: iconst_1
       194: ldc           #209                // class bencode/type/BDictionary
       196: aastore
       197: dup
       198: iconst_2
       199: aload_3
       200: invokevirtual #220                // Method bencode/type/BDictionary.getContent:()Ljava/util/TreeMap;
       203: aastore
       204: dup
       205: iconst_3
       206: aload_3
       207: invokevirtual #223                // Method bencode/type/BDictionary.getContentLength:()I
       210: invokestatic  #83                 // Method java/lang/Integer.valueOf:(I)Ljava/lang/Integer;
       213: aastore
       214: invokeinterface #166,  3          // InterfaceMethod org/slf4j/Logger.debug:(Ljava/lang/String;[Ljava/lang/Object;)V
       219: aload_3
       220: areturn
      LineNumberTable:
        line 288: 0
        line 289: 8
        line 290: 13
        line 292: 17
        line 293: 24
        line 294: 27
        line 296: 29
        line 293: 33
        line 297: 38
        line 298: 42
        line 299: 51
        line 298: 55
        line 297: 58
        line 302: 62
        line 303: 71
        line 308: 73
        line 309: 82
        line 312: 92
        line 313: 101
        line 315: 113
        line 317: 122
        line 318: 129
        line 319: 132
        line 321: 134
        line 318: 138
        line 322: 143
        line 323: 147
        line 324: 156
        line 323: 160
        line 322: 163
        line 325: 167
        line 330: 176
        line 331: 179
        line 332: 187
        line 333: 199
        line 330: 214
        line 335: 219
      LocalVariableTable:
        Start  Length  Slot  Name   Signature
            0     221     0  this   Lbencode/parse/Parser;
            0     221     1 content   [B
            0     221     2 offset   I
            8     213     3 bDictionary   Lbencode/type/BDictionary;
           13     208     4     i   I
           17     204     5 contentLength   I
           82      94     6   key   Lbencode/type/BString;
          101      75     7 value   Lbencode/type/BType;
      LocalVariableTypeTable:
        Start  Length  Slot  Name   Signature
          101      75     7 value   Lbencode/type/BType<*>;
      StackMapTable: number_of_entries = 3
        frame_type = 254 /* append */
          offset_delta = 62
          locals = [ class bencode/type/BDictionary, int, int ]
        frame_type = 10 /* same */
        frame_type = 253 /* append */
          offset_delta = 93
          locals = [ class bencode/type/BString, class bencode/type/BType ]
}
SourceFile: "Parser.java"
