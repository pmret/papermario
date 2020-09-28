.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osPfsChecker
/* 48020 8006CC20 27BDFB60 */  addiu     $sp, $sp, -0x4a0
/* 48024 8006CC24 AFB1047C */  sw        $s1, 0x47c($sp)
/* 48028 8006CC28 00808821 */  addu      $s1, $a0, $zero
/* 4802C 8006CC2C AFBE0498 */  sw        $fp, 0x498($sp)
/* 48030 8006CC30 0000F021 */  addu      $fp, $zero, $zero
/* 48034 8006CC34 AFB60490 */  sw        $s6, 0x490($sp)
/* 48038 8006CC38 241600FE */  addiu     $s6, $zero, 0xfe
/* 4803C 8006CC3C AFBF049C */  sw        $ra, 0x49c($sp)
/* 48040 8006CC40 AFB70494 */  sw        $s7, 0x494($sp)
/* 48044 8006CC44 AFB5048C */  sw        $s5, 0x48c($sp)
/* 48048 8006CC48 AFB40488 */  sw        $s4, 0x488($sp)
/* 4804C 8006CC4C AFB30484 */  sw        $s3, 0x484($sp)
/* 48050 8006CC50 AFB20480 */  sw        $s2, 0x480($sp)
/* 48054 8006CC54 0C01A775 */  jal       osCheckId
/* 48058 8006CC58 AFB00478 */   sw       $s0, 0x478($sp)
/* 4805C 8006CC5C 00408021 */  addu      $s0, $v0, $zero
/* 48060 8006CC60 24020002 */  addiu     $v0, $zero, 2
/* 48064 8006CC64 16020004 */  bne       $s0, $v0, .L8006CC78
/* 48068 8006CC68 00000000 */   nop      
/* 4806C 8006CC6C 0C01A702 */  jal       osGetId
/* 48070 8006CC70 02202021 */   addu     $a0, $s1, $zero
/* 48074 8006CC74 00408021 */  addu      $s0, $v0, $zero
.L8006CC78:
/* 48078 8006CC78 12000003 */  beqz      $s0, .L8006CC88
/* 4807C 8006CC7C 02202021 */   addu     $a0, $s1, $zero
.L8006CC80:
/* 48080 8006CC80 0801B414 */  j         .L8006D050
/* 48084 8006CC84 02001021 */   addu     $v0, $s0, $zero
.L8006CC88:
/* 48088 8006CC88 0C01B420 */  jal       corrupted_init
/* 4808C 8006CC8C 27A50258 */   addiu    $a1, $sp, 0x258
/* 48090 8006CC90 00408021 */  addu      $s0, $v0, $zero
/* 48094 8006CC94 160000EE */  bnez      $s0, .L8006D050
/* 48098 8006CC98 00000000 */   nop      
/* 4809C 8006CC9C 8E220050 */  lw        $v0, 0x50($s1)
/* 480A0 8006CCA0 0202102A */  slt       $v0, $s0, $v0
/* 480A4 8006CCA4 1040006B */  beqz      $v0, .L8006CE54
/* 480A8 8006CCA8 00009021 */   addu     $s2, $zero, $zero
/* 480AC 8006CCAC 27B70018 */  addiu     $s7, $sp, 0x18
.L8006CCB0:
/* 480B0 8006CCB0 8E240004 */  lw        $a0, 4($s1)
/* 480B4 8006CCB4 8E26005C */  lw        $a2, 0x5c($s1)
/* 480B8 8006CCB8 8E250008 */  lw        $a1, 8($s1)
/* 480BC 8006CCBC 27A70218 */  addiu     $a3, $sp, 0x218
/* 480C0 8006CCC0 00D23021 */  addu      $a2, $a2, $s2
/* 480C4 8006CCC4 0C01A874 */  jal       osContRamRead
/* 480C8 8006CCC8 30C6FFFF */   andi     $a2, $a2, 0xffff
/* 480CC 8006CCCC 00408021 */  addu      $s0, $v0, $zero
/* 480D0 8006CCD0 160000DF */  bnez      $s0, .L8006D050
/* 480D4 8006CCD4 02001021 */   addu     $v0, $s0, $zero
/* 480D8 8006CCD8 97A2021C */  lhu       $v0, 0x21c($sp)
/* 480DC 8006CCDC 14400006 */  bnez      $v0, .L8006CCF8
/* 480E0 8006CCE0 00000000 */   nop      
/* 480E4 8006CCE4 8FA20218 */  lw        $v0, 0x218($sp)
/* 480E8 8006CCE8 10400055 */  beqz      $v0, .L8006CE40
/* 480EC 8006CCEC 2405FFFF */   addiu    $a1, $zero, -1
/* 480F0 8006CCF0 0801B374 */  j         .L8006CDD0
/* 480F4 8006CCF4 00000000 */   nop      
.L8006CCF8:
/* 480F8 8006CCF8 8FA20218 */  lw        $v0, 0x218($sp)
/* 480FC 8006CCFC 14400003 */  bnez      $v0, .L8006CD0C
/* 48100 8006CD00 00002821 */   addu     $a1, $zero, $zero
/* 48104 8006CD04 0801B374 */  j         .L8006CDD0
/* 48108 8006CD08 2405FFFF */   addiu    $a1, $zero, -1
.L8006CD0C:
/* 4810C 8006CD0C 97B4021E */  lhu       $s4, 0x21e($sp)
/* 48110 8006CD10 0000A821 */  addu      $s5, $zero, $zero
/* 48114 8006CD14 8E220060 */  lw        $v0, 0x60($s1)
/* 48118 8006CD18 0801B36C */  j         .L8006CDB0
/* 4811C 8006CD1C 241300FF */   addiu    $s3, $zero, 0xff
.L8006CD20:
/* 48120 8006CD20 0002182B */  sltu      $v1, $zero, $v0
/* 48124 8006CD24 2C420080 */  sltiu     $v0, $v0, 0x80
/* 48128 8006CD28 00621824 */  and       $v1, $v1, $v0
/* 4812C 8006CD2C 10600028 */  beqz      $v1, .L8006CDD0
/* 48130 8006CD30 00041A02 */   srl      $v1, $a0, 8
/* 48134 8006CD34 326200FF */  andi      $v0, $s3, 0xff
/* 48138 8006CD38 306700FF */  andi      $a3, $v1, 0xff
/* 4813C 8006CD3C 1047000F */  beq       $v0, $a3, .L8006CD7C
/* 48140 8006CD40 32C200FF */   andi     $v0, $s6, 0xff
/* 48144 8006CD44 10470007 */  beq       $v0, $a3, .L8006CD64
/* 48148 8006CD48 00609821 */   addu     $s3, $v1, $zero
/* 4814C 8006CD4C 02202021 */  addu      $a0, $s1, $zero
/* 48150 8006CD50 27A50118 */  addiu     $a1, $sp, 0x118
/* 48154 8006CD54 0C01A7A3 */  jal       osPfsRWInode
/* 48158 8006CD58 00003021 */   addu     $a2, $zero, $zero
/* 4815C 8006CD5C 00408021 */  addu      $s0, $v0, $zero
/* 48160 8006CD60 0260B021 */  addu      $s6, $s3, $zero
.L8006CD64:
/* 48164 8006CD64 0010182B */  sltu      $v1, $zero, $s0
/* 48168 8006CD68 3A020003 */  xori      $v0, $s0, 3
/* 4816C 8006CD6C 0002102B */  sltu      $v0, $zero, $v0
/* 48170 8006CD70 00621824 */  and       $v1, $v1, $v0
/* 48174 8006CD74 146000B6 */  bnez      $v1, .L8006D050
/* 48178 8006CD78 02001021 */   addu     $v0, $s0, $zero
.L8006CD7C:
/* 4817C 8006CD7C 02202021 */  addu      $a0, $s1, $zero
/* 48180 8006CD80 02802821 */  addu      $a1, $s4, $zero
/* 48184 8006CD84 27A60258 */  addiu     $a2, $sp, 0x258
/* 48188 8006CD88 0C01B476 */  jal       corrupted
/* 4818C 8006CD8C 00052C00 */   sll      $a1, $a1, 0x10
/* 48190 8006CD90 00552823 */  subu      $a1, $v0, $s5
/* 48194 8006CD94 14A00014 */  bnez      $a1, .L8006CDE8
/* 48198 8006CD98 328200FF */   andi     $v0, $s4, 0xff
/* 4819C 8006CD9C 00021040 */  sll       $v0, $v0, 1
/* 481A0 8006CDA0 00571021 */  addu      $v0, $v0, $s7
/* 481A4 8006CDA4 94540100 */  lhu       $s4, 0x100($v0)
/* 481A8 8006CDA8 8E220060 */  lw        $v0, 0x60($s1)
/* 481AC 8006CDAC 24150001 */  addiu     $s5, $zero, 1
.L8006CDB0:
/* 481B0 8006CDB0 3284FFFF */  andi      $a0, $s4, 0xffff
/* 481B4 8006CDB4 0082102A */  slt       $v0, $a0, $v0
/* 481B8 8006CDB8 14400005 */  bnez      $v0, .L8006CDD0
/* 481BC 8006CDBC 00041202 */   srl      $v0, $a0, 8
/* 481C0 8006CDC0 92230064 */  lbu       $v1, 0x64($s1)
/* 481C4 8006CDC4 0043102B */  sltu      $v0, $v0, $v1
/* 481C8 8006CDC8 1440FFD5 */  bnez      $v0, .L8006CD20
/* 481CC 8006CDCC 328200FF */   andi     $v0, $s4, 0xff
.L8006CDD0:
/* 481D0 8006CDD0 54A00006 */  bnel      $a1, $zero, .L8006CDEC
/* 481D4 8006CDD4 27A40218 */   addiu    $a0, $sp, 0x218
/* 481D8 8006CDD8 3283FFFF */  andi      $v1, $s4, 0xffff
/* 481DC 8006CDDC 24020001 */  addiu     $v0, $zero, 1
/* 481E0 8006CDE0 10620017 */  beq       $v1, $v0, .L8006CE40
/* 481E4 8006CDE4 00000000 */   nop      
.L8006CDE8:
/* 481E8 8006CDE8 27A40218 */  addiu     $a0, $sp, 0x218
.L8006CDEC:
/* 481EC 8006CDEC 0C01925C */  jal       bzero
/* 481F0 8006CDF0 24050020 */   addiu    $a1, $zero, 0x20
/* 481F4 8006CDF4 92220065 */  lbu       $v0, 0x65($s1)
/* 481F8 8006CDF8 10400006 */  beqz      $v0, .L8006CE14
/* 481FC 8006CDFC 02202021 */   addu     $a0, $s1, $zero
/* 48200 8006CE00 0C01A5B4 */  jal       osPfsSelectBank
/* 48204 8006CE04 00002821 */   addu     $a1, $zero, $zero
/* 48208 8006CE08 00408021 */  addu      $s0, $v0, $zero
/* 4820C 8006CE0C 16000090 */  bnez      $s0, .L8006D050
/* 48210 8006CE10 02001021 */   addu     $v0, $s0, $zero
.L8006CE14:
/* 48214 8006CE14 8E26005C */  lw        $a2, 0x5c($s1)
/* 48218 8006CE18 AFA00010 */  sw        $zero, 0x10($sp)
/* 4821C 8006CE1C 8E240004 */  lw        $a0, 4($s1)
/* 48220 8006CE20 8E250008 */  lw        $a1, 8($s1)
/* 48224 8006CE24 27A70218 */  addiu     $a3, $sp, 0x218
/* 48228 8006CE28 00D23021 */  addu      $a2, $a2, $s2
/* 4822C 8006CE2C 0C01A8F0 */  jal       osContRamWrite
/* 48230 8006CE30 30C6FFFF */   andi     $a2, $a2, 0xffff
/* 48234 8006CE34 00408021 */  addu      $s0, $v0, $zero
/* 48238 8006CE38 1600FF91 */  bnez      $s0, .L8006CC80
/* 4823C 8006CE3C 27DE0001 */   addiu    $fp, $fp, 1
.L8006CE40:
/* 48240 8006CE40 8E220050 */  lw        $v0, 0x50($s1)
/* 48244 8006CE44 26520001 */  addiu     $s2, $s2, 1
/* 48248 8006CE48 0242102A */  slt       $v0, $s2, $v0
/* 4824C 8006CE4C 1440FF98 */  bnez      $v0, .L8006CCB0
/* 48250 8006CE50 00000000 */   nop      
.L8006CE54:
/* 48254 8006CE54 8E220050 */  lw        $v0, 0x50($s1)
/* 48258 8006CE58 1840001D */  blez      $v0, .L8006CED0
/* 4825C 8006CE5C 00009021 */   addu     $s2, $zero, $zero
/* 48260 8006CE60 27B30238 */  addiu     $s3, $sp, 0x238
.L8006CE64:
/* 48264 8006CE64 8E240004 */  lw        $a0, 4($s1)
/* 48268 8006CE68 8E26005C */  lw        $a2, 0x5c($s1)
/* 4826C 8006CE6C 8E250008 */  lw        $a1, 8($s1)
/* 48270 8006CE70 27A70218 */  addiu     $a3, $sp, 0x218
/* 48274 8006CE74 00D23021 */  addu      $a2, $a2, $s2
/* 48278 8006CE78 0C01A874 */  jal       osContRamRead
/* 4827C 8006CE7C 30C6FFFF */   andi     $a2, $a2, 0xffff
/* 48280 8006CE80 00408021 */  addu      $s0, $v0, $zero
/* 48284 8006CE84 16000072 */  bnez      $s0, .L8006D050
/* 48288 8006CE88 02001021 */   addu     $v0, $s0, $zero
/* 4828C 8006CE8C 97A2021C */  lhu       $v0, 0x21c($sp)
/* 48290 8006CE90 5040000A */  beql      $v0, $zero, .L8006CEBC
/* 48294 8006CE94 A6600000 */   sh       $zero, ($s3)
/* 48298 8006CE98 8FA20218 */  lw        $v0, 0x218($sp)
/* 4829C 8006CE9C 50400007 */  beql      $v0, $zero, .L8006CEBC
/* 482A0 8006CEA0 A6600000 */   sh       $zero, ($s3)
/* 482A4 8006CEA4 97A3021E */  lhu       $v1, 0x21e($sp)
/* 482A8 8006CEA8 96220062 */  lhu       $v0, 0x62($s1)
/* 482AC 8006CEAC 0062102B */  sltu      $v0, $v1, $v0
/* 482B0 8006CEB0 54400002 */  bnel      $v0, $zero, .L8006CEBC
/* 482B4 8006CEB4 A6600000 */   sh       $zero, ($s3)
/* 482B8 8006CEB8 A6630000 */  sh        $v1, ($s3)
.L8006CEBC:
/* 482BC 8006CEBC 8E220050 */  lw        $v0, 0x50($s1)
/* 482C0 8006CEC0 26520001 */  addiu     $s2, $s2, 1
/* 482C4 8006CEC4 0242102A */  slt       $v0, $s2, $v0
/* 482C8 8006CEC8 1440FFE6 */  bnez      $v0, .L8006CE64
/* 482CC 8006CECC 26730002 */   addiu    $s3, $s3, 2
.L8006CED0:
/* 482D0 8006CED0 92220064 */  lbu       $v0, 0x64($s1)
/* 482D4 8006CED4 10400055 */  beqz      $v0, .L8006D02C
/* 482D8 8006CED8 00009821 */   addu     $s3, $zero, $zero
/* 482DC 8006CEDC 27B40018 */  addiu     $s4, $sp, 0x18
/* 482E0 8006CEE0 27B60118 */  addiu     $s6, $sp, 0x118
/* 482E4 8006CEE4 27B50238 */  addiu     $s5, $sp, 0x238
/* 482E8 8006CEE8 02202021 */  addu      $a0, $s1, $zero
.L8006CEEC:
/* 482EC 8006CEEC 27A50118 */  addiu     $a1, $sp, 0x118
/* 482F0 8006CEF0 00003021 */  addu      $a2, $zero, $zero
/* 482F4 8006CEF4 327200FF */  andi      $s2, $s3, 0xff
/* 482F8 8006CEF8 0C01A7A3 */  jal       osPfsRWInode
/* 482FC 8006CEFC 02403821 */   addu     $a3, $s2, $zero
/* 48300 8006CF00 00408021 */  addu      $s0, $v0, $zero
/* 48304 8006CF04 0010182B */  sltu      $v1, $zero, $s0
/* 48308 8006CF08 3A020003 */  xori      $v0, $s0, 3
/* 4830C 8006CF0C 0002102B */  sltu      $v0, $zero, $v0
/* 48310 8006CF10 00621824 */  and       $v1, $v1, $v0
/* 48314 8006CF14 5460004E */  bnel      $v1, $zero, .L8006D050
/* 48318 8006CF18 02001021 */   addu     $v0, $s0, $zero
/* 4831C 8006CF1C 16400002 */  bnez      $s2, .L8006CF28
/* 48320 8006CF20 24050001 */   addiu    $a1, $zero, 1
/* 48324 8006CF24 8E250060 */  lw        $a1, 0x60($s1)
.L8006CF28:
/* 48328 8006CF28 18A0000A */  blez      $a1, .L8006CF54
/* 4832C 8006CF2C 00009021 */   addu     $s2, $zero, $zero
/* 48330 8006CF30 02802021 */  addu      $a0, $s4, $zero
/* 48334 8006CF34 02C01821 */  addu      $v1, $s6, $zero
.L8006CF38:
/* 48338 8006CF38 94620000 */  lhu       $v0, ($v1)
/* 4833C 8006CF3C 24630002 */  addiu     $v1, $v1, 2
/* 48340 8006CF40 26520001 */  addiu     $s2, $s2, 1
/* 48344 8006CF44 A4820000 */  sh        $v0, ($a0)
/* 48348 8006CF48 0245102A */  slt       $v0, $s2, $a1
/* 4834C 8006CF4C 1440FFFA */  bnez      $v0, .L8006CF38
/* 48350 8006CF50 24840002 */   addiu    $a0, $a0, 2
.L8006CF54:
/* 48354 8006CF54 2A420080 */  slti      $v0, $s2, 0x80
/* 48358 8006CF58 10400008 */  beqz      $v0, .L8006CF7C
/* 4835C 8006CF5C 00121040 */   sll      $v0, $s2, 1
/* 48360 8006CF60 24040003 */  addiu     $a0, $zero, 3
/* 48364 8006CF64 00541821 */  addu      $v1, $v0, $s4
.L8006CF68:
/* 48368 8006CF68 A4640000 */  sh        $a0, ($v1)
/* 4836C 8006CF6C 26520001 */  addiu     $s2, $s2, 1
/* 48370 8006CF70 2A420080 */  slti      $v0, $s2, 0x80
/* 48374 8006CF74 1440FFFC */  bnez      $v0, .L8006CF68
/* 48378 8006CF78 24630002 */   addiu    $v1, $v1, 2
.L8006CF7C:
/* 4837C 8006CF7C 8E220050 */  lw        $v0, 0x50($s1)
/* 48380 8006CF80 1840001D */  blez      $v0, .L8006CFF8
/* 48384 8006CF84 00009021 */   addu     $s2, $zero, $zero
/* 48388 8006CF88 326800FF */  andi      $t0, $s3, 0xff
/* 4838C 8006CF8C 00003021 */  addu      $a2, $zero, $zero
/* 48390 8006CF90 02A03821 */  addu      $a3, $s5, $zero
.L8006CF94:
/* 48394 8006CF94 90E20000 */  lbu       $v0, ($a3)
/* 48398 8006CF98 14480011 */  bne       $v0, $t0, .L8006CFE0
/* 4839C 8006CF9C 02A02821 */   addu     $a1, $s5, $zero
.L8006CFA0:
/* 483A0 8006CFA0 00A62021 */  addu      $a0, $a1, $a2
/* 483A4 8006CFA4 94830000 */  lhu       $v1, ($a0)
/* 483A8 8006CFA8 96220062 */  lhu       $v0, 0x62($s1)
/* 483AC 8006CFAC 0062182B */  sltu      $v1, $v1, $v0
/* 483B0 8006CFB0 5460000C */  bnel      $v1, $zero, .L8006CFE4
/* 483B4 8006CFB4 24C60002 */   addiu    $a2, $a2, 2
/* 483B8 8006CFB8 90820001 */  lbu       $v0, 1($a0)
/* 483BC 8006CFBC 00021040 */  sll       $v0, $v0, 1
/* 483C0 8006CFC0 00541021 */  addu      $v0, $v0, $s4
/* 483C4 8006CFC4 94430100 */  lhu       $v1, 0x100($v0)
/* 483C8 8006CFC8 A4430000 */  sh        $v1, ($v0)
/* 483CC 8006CFCC 00D41021 */  addu      $v0, $a2, $s4
/* 483D0 8006CFD0 A4430220 */  sh        $v1, 0x220($v0)
/* 483D4 8006CFD4 90820000 */  lbu       $v0, ($a0)
/* 483D8 8006CFD8 1048FFF1 */  beq       $v0, $t0, .L8006CFA0
/* 483DC 8006CFDC 00000000 */   nop      
.L8006CFE0:
/* 483E0 8006CFE0 24C60002 */  addiu     $a2, $a2, 2
.L8006CFE4:
/* 483E4 8006CFE4 8E220050 */  lw        $v0, 0x50($s1)
/* 483E8 8006CFE8 26520001 */  addiu     $s2, $s2, 1
/* 483EC 8006CFEC 0242102A */  slt       $v0, $s2, $v0
/* 483F0 8006CFF0 1440FFE8 */  bnez      $v0, .L8006CF94
/* 483F4 8006CFF4 24E70002 */   addiu    $a3, $a3, 2
.L8006CFF8:
/* 483F8 8006CFF8 02202021 */  addu      $a0, $s1, $zero
/* 483FC 8006CFFC 27A50018 */  addiu     $a1, $sp, 0x18
/* 48400 8006D000 24060001 */  addiu     $a2, $zero, 1
/* 48404 8006D004 0C01A7A3 */  jal       osPfsRWInode
/* 48408 8006D008 326700FF */   andi     $a3, $s3, 0xff
/* 4840C 8006D00C 00408021 */  addu      $s0, $v0, $zero
/* 48410 8006D010 1600FF1B */  bnez      $s0, .L8006CC80
/* 48414 8006D014 26730001 */   addiu    $s3, $s3, 1
/* 48418 8006D018 92230064 */  lbu       $v1, 0x64($s1)
/* 4841C 8006D01C 326200FF */  andi      $v0, $s3, 0xff
/* 48420 8006D020 0043102B */  sltu      $v0, $v0, $v1
/* 48424 8006D024 1440FFB1 */  bnez      $v0, .L8006CEEC
/* 48428 8006D028 02202021 */   addu     $a0, $s1, $zero
.L8006D02C:
/* 4842C 8006D02C 13C00004 */  beqz      $fp, .L8006D040
/* 48430 8006D030 2403FFFD */   addiu    $v1, $zero, -3
/* 48434 8006D034 8E220000 */  lw        $v0, ($s1)
/* 48438 8006D038 0801B412 */  j         .L8006D048
/* 4843C 8006D03C 34420002 */   ori      $v0, $v0, 2
.L8006D040:
/* 48440 8006D040 8E220000 */  lw        $v0, ($s1)
/* 48444 8006D044 00431024 */  and       $v0, $v0, $v1
.L8006D048:
/* 48448 8006D048 AE220000 */  sw        $v0, ($s1)
/* 4844C 8006D04C 00001021 */  addu      $v0, $zero, $zero
.L8006D050:
/* 48450 8006D050 8FBF049C */  lw        $ra, 0x49c($sp)
/* 48454 8006D054 8FBE0498 */  lw        $fp, 0x498($sp)
/* 48458 8006D058 8FB70494 */  lw        $s7, 0x494($sp)
/* 4845C 8006D05C 8FB60490 */  lw        $s6, 0x490($sp)
/* 48460 8006D060 8FB5048C */  lw        $s5, 0x48c($sp)
/* 48464 8006D064 8FB40488 */  lw        $s4, 0x488($sp)
/* 48468 8006D068 8FB30484 */  lw        $s3, 0x484($sp)
/* 4846C 8006D06C 8FB20480 */  lw        $s2, 0x480($sp)
/* 48470 8006D070 8FB1047C */  lw        $s1, 0x47c($sp)
/* 48474 8006D074 8FB00478 */  lw        $s0, 0x478($sp)
/* 48478 8006D078 03E00008 */  jr        $ra
/* 4847C 8006D07C 27BD04A0 */   addiu    $sp, $sp, 0x4a0
