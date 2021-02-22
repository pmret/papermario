.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006CC00
/* 48000 8006CC00 27BDFB60 */  addiu     $sp, $sp, -0x4a0
/* 48004 8006CC04 AFB1047C */  sw        $s1, 0x47c($sp)
/* 48008 8006CC08 00808821 */  addu      $s1, $a0, $zero
/* 4800C 8006CC0C AFBE0498 */  sw        $fp, 0x498($sp)
/* 48010 8006CC10 0000F021 */  addu      $fp, $zero, $zero
/* 48014 8006CC14 AFB60490 */  sw        $s6, 0x490($sp)
/* 48018 8006CC18 241600FE */  addiu     $s6, $zero, 0xfe
/* 4801C 8006CC1C AFBF049C */  sw        $ra, 0x49c($sp)
/* 48020 8006CC20 AFB70494 */  sw        $s7, 0x494($sp)
/* 48024 8006CC24 AFB5048C */  sw        $s5, 0x48c($sp)
/* 48028 8006CC28 AFB40488 */  sw        $s4, 0x488($sp)
/* 4802C 8006CC2C AFB30484 */  sw        $s3, 0x484($sp)
/* 48030 8006CC30 AFB20480 */  sw        $s2, 0x480($sp)
/* 48034 8006CC34 0C01A76D */  jal       func_80069DB4
/* 48038 8006CC38 AFB00478 */   sw       $s0, 0x478($sp)
/* 4803C 8006CC3C 00408021 */  addu      $s0, $v0, $zero
/* 48040 8006CC40 24020002 */  addiu     $v0, $zero, 2
/* 48044 8006CC44 16020004 */  bne       $s0, $v0, .L8006CC58
/* 48048 8006CC48 00000000 */   nop
/* 4804C 8006CC4C 0C01A6FA */  jal       func_80069BE8
/* 48050 8006CC50 02202021 */   addu     $a0, $s1, $zero
/* 48054 8006CC54 00408021 */  addu      $s0, $v0, $zero
.L8006CC58:
/* 48058 8006CC58 12000003 */  beqz      $s0, .L8006CC68
/* 4805C 8006CC5C 02202021 */   addu     $a0, $s1, $zero
.L8006CC60:
/* 48060 8006CC60 0801B40C */  j         .L8006D030
/* 48064 8006CC64 02001021 */   addu     $v0, $s0, $zero
.L8006CC68:
/* 48068 8006CC68 0C01B418 */  jal       func_8006D060
/* 4806C 8006CC6C 27A50258 */   addiu    $a1, $sp, 0x258
/* 48070 8006CC70 00408021 */  addu      $s0, $v0, $zero
/* 48074 8006CC74 160000EE */  bnez      $s0, .L8006D030
/* 48078 8006CC78 00000000 */   nop
/* 4807C 8006CC7C 8E220050 */  lw        $v0, 0x50($s1)
/* 48080 8006CC80 0202102A */  slt       $v0, $s0, $v0
/* 48084 8006CC84 1040006B */  beqz      $v0, .L8006CE34
/* 48088 8006CC88 00009021 */   addu     $s2, $zero, $zero
/* 4808C 8006CC8C 27B70018 */  addiu     $s7, $sp, 0x18
.L8006CC90:
/* 48090 8006CC90 8E240004 */  lw        $a0, 4($s1)
/* 48094 8006CC94 8E26005C */  lw        $a2, 0x5c($s1)
/* 48098 8006CC98 8E250008 */  lw        $a1, 8($s1)
/* 4809C 8006CC9C 27A70218 */  addiu     $a3, $sp, 0x218
/* 480A0 8006CCA0 00D23021 */  addu      $a2, $a2, $s2
/* 480A4 8006CCA4 0C01A86C */  jal       func_8006A1B0
/* 480A8 8006CCA8 30C6FFFF */   andi     $a2, $a2, 0xffff
/* 480AC 8006CCAC 00408021 */  addu      $s0, $v0, $zero
/* 480B0 8006CCB0 160000DF */  bnez      $s0, .L8006D030
/* 480B4 8006CCB4 02001021 */   addu     $v0, $s0, $zero
/* 480B8 8006CCB8 97A2021C */  lhu       $v0, 0x21c($sp)
/* 480BC 8006CCBC 14400006 */  bnez      $v0, .L8006CCD8
/* 480C0 8006CCC0 00000000 */   nop
/* 480C4 8006CCC4 8FA20218 */  lw        $v0, 0x218($sp)
/* 480C8 8006CCC8 10400055 */  beqz      $v0, .L8006CE20
/* 480CC 8006CCCC 2405FFFF */   addiu    $a1, $zero, -1
/* 480D0 8006CCD0 0801B36C */  j         .L8006CDB0
/* 480D4 8006CCD4 00000000 */   nop
.L8006CCD8:
/* 480D8 8006CCD8 8FA20218 */  lw        $v0, 0x218($sp)
/* 480DC 8006CCDC 14400003 */  bnez      $v0, .L8006CCEC
/* 480E0 8006CCE0 00002821 */   addu     $a1, $zero, $zero
/* 480E4 8006CCE4 0801B36C */  j         .L8006CDB0
/* 480E8 8006CCE8 2405FFFF */   addiu    $a1, $zero, -1
.L8006CCEC:
/* 480EC 8006CCEC 97B4021E */  lhu       $s4, 0x21e($sp)
/* 480F0 8006CCF0 0000A821 */  addu      $s5, $zero, $zero
/* 480F4 8006CCF4 8E220060 */  lw        $v0, 0x60($s1)
/* 480F8 8006CCF8 0801B364 */  j         .L8006CD90
/* 480FC 8006CCFC 241300FF */   addiu    $s3, $zero, 0xff
.L8006CD00:
/* 48100 8006CD00 0002182B */  sltu      $v1, $zero, $v0
/* 48104 8006CD04 2C420080 */  sltiu     $v0, $v0, 0x80
/* 48108 8006CD08 00621824 */  and       $v1, $v1, $v0
/* 4810C 8006CD0C 10600028 */  beqz      $v1, .L8006CDB0
/* 48110 8006CD10 00041A02 */   srl      $v1, $a0, 8
/* 48114 8006CD14 326200FF */  andi      $v0, $s3, 0xff
/* 48118 8006CD18 306700FF */  andi      $a3, $v1, 0xff
/* 4811C 8006CD1C 1047000F */  beq       $v0, $a3, .L8006CD5C
/* 48120 8006CD20 32C200FF */   andi     $v0, $s6, 0xff
/* 48124 8006CD24 10470007 */  beq       $v0, $a3, .L8006CD44
/* 48128 8006CD28 00609821 */   addu     $s3, $v1, $zero
/* 4812C 8006CD2C 02202021 */  addu      $a0, $s1, $zero
/* 48130 8006CD30 27A50118 */  addiu     $a1, $sp, 0x118
/* 48134 8006CD34 0C01A79B */  jal       func_80069E6C
/* 48138 8006CD38 00003021 */   addu     $a2, $zero, $zero
/* 4813C 8006CD3C 00408021 */  addu      $s0, $v0, $zero
/* 48140 8006CD40 0260B021 */  addu      $s6, $s3, $zero
.L8006CD44:
/* 48144 8006CD44 0010182B */  sltu      $v1, $zero, $s0
/* 48148 8006CD48 3A020003 */  xori      $v0, $s0, 3
/* 4814C 8006CD4C 0002102B */  sltu      $v0, $zero, $v0
/* 48150 8006CD50 00621824 */  and       $v1, $v1, $v0
/* 48154 8006CD54 146000B6 */  bnez      $v1, .L8006D030
/* 48158 8006CD58 02001021 */   addu     $v0, $s0, $zero
.L8006CD5C:
/* 4815C 8006CD5C 02202021 */  addu      $a0, $s1, $zero
/* 48160 8006CD60 02802821 */  addu      $a1, $s4, $zero
/* 48164 8006CD64 27A60258 */  addiu     $a2, $sp, 0x258
/* 48168 8006CD68 0C01B46E */  jal       func_8006D1B8
/* 4816C 8006CD6C 00052C00 */   sll      $a1, $a1, 0x10
/* 48170 8006CD70 00552823 */  subu      $a1, $v0, $s5
/* 48174 8006CD74 14A00014 */  bnez      $a1, .L8006CDC8
/* 48178 8006CD78 328200FF */   andi     $v0, $s4, 0xff
/* 4817C 8006CD7C 00021040 */  sll       $v0, $v0, 1
/* 48180 8006CD80 00571021 */  addu      $v0, $v0, $s7
/* 48184 8006CD84 94540100 */  lhu       $s4, 0x100($v0)
/* 48188 8006CD88 8E220060 */  lw        $v0, 0x60($s1)
/* 4818C 8006CD8C 24150001 */  addiu     $s5, $zero, 1
.L8006CD90:
/* 48190 8006CD90 3284FFFF */  andi      $a0, $s4, 0xffff
/* 48194 8006CD94 0082102A */  slt       $v0, $a0, $v0
/* 48198 8006CD98 14400005 */  bnez      $v0, .L8006CDB0
/* 4819C 8006CD9C 00041202 */   srl      $v0, $a0, 8
/* 481A0 8006CDA0 92230064 */  lbu       $v1, 0x64($s1)
/* 481A4 8006CDA4 0043102B */  sltu      $v0, $v0, $v1
/* 481A8 8006CDA8 1440FFD5 */  bnez      $v0, .L8006CD00
/* 481AC 8006CDAC 328200FF */   andi     $v0, $s4, 0xff
.L8006CDB0:
/* 481B0 8006CDB0 54A00006 */  bnel      $a1, $zero, .L8006CDCC
/* 481B4 8006CDB4 27A40218 */   addiu    $a0, $sp, 0x218
/* 481B8 8006CDB8 3283FFFF */  andi      $v1, $s4, 0xffff
/* 481BC 8006CDBC 24020001 */  addiu     $v0, $zero, 1
/* 481C0 8006CDC0 10620017 */  beq       $v1, $v0, .L8006CE20
/* 481C4 8006CDC4 00000000 */   nop
.L8006CDC8:
/* 481C8 8006CDC8 27A40218 */  addiu     $a0, $sp, 0x218
.L8006CDCC:
/* 481CC 8006CDCC 0C019250 */  jal       func_80064940
/* 481D0 8006CDD0 24050020 */   addiu    $a1, $zero, 0x20
/* 481D4 8006CDD4 92220065 */  lbu       $v0, 0x65($s1)
/* 481D8 8006CDD8 10400006 */  beqz      $v0, .L8006CDF4
/* 481DC 8006CDDC 02202021 */   addu     $a0, $s1, $zero
/* 481E0 8006CDE0 0C01A5AC */  jal       func_800696B0
/* 481E4 8006CDE4 00002821 */   addu     $a1, $zero, $zero
/* 481E8 8006CDE8 00408021 */  addu      $s0, $v0, $zero
/* 481EC 8006CDEC 16000090 */  bnez      $s0, .L8006D030
/* 481F0 8006CDF0 02001021 */   addu     $v0, $s0, $zero
.L8006CDF4:
/* 481F4 8006CDF4 8E26005C */  lw        $a2, 0x5c($s1)
/* 481F8 8006CDF8 AFA00010 */  sw        $zero, 0x10($sp)
/* 481FC 8006CDFC 8E240004 */  lw        $a0, 4($s1)
/* 48200 8006CE00 8E250008 */  lw        $a1, 8($s1)
/* 48204 8006CE04 27A70218 */  addiu     $a3, $sp, 0x218
/* 48208 8006CE08 00D23021 */  addu      $a2, $a2, $s2
/* 4820C 8006CE0C 0C01A8E8 */  jal       func_8006A3A0
/* 48210 8006CE10 30C6FFFF */   andi     $a2, $a2, 0xffff
/* 48214 8006CE14 00408021 */  addu      $s0, $v0, $zero
/* 48218 8006CE18 1600FF91 */  bnez      $s0, .L8006CC60
/* 4821C 8006CE1C 27DE0001 */   addiu    $fp, $fp, 1
.L8006CE20:
/* 48220 8006CE20 8E220050 */  lw        $v0, 0x50($s1)
/* 48224 8006CE24 26520001 */  addiu     $s2, $s2, 1
/* 48228 8006CE28 0242102A */  slt       $v0, $s2, $v0
/* 4822C 8006CE2C 1440FF98 */  bnez      $v0, .L8006CC90
/* 48230 8006CE30 00000000 */   nop
.L8006CE34:
/* 48234 8006CE34 8E220050 */  lw        $v0, 0x50($s1)
/* 48238 8006CE38 1840001D */  blez      $v0, .L8006CEB0
/* 4823C 8006CE3C 00009021 */   addu     $s2, $zero, $zero
/* 48240 8006CE40 27B30238 */  addiu     $s3, $sp, 0x238
.L8006CE44:
/* 48244 8006CE44 8E240004 */  lw        $a0, 4($s1)
/* 48248 8006CE48 8E26005C */  lw        $a2, 0x5c($s1)
/* 4824C 8006CE4C 8E250008 */  lw        $a1, 8($s1)
/* 48250 8006CE50 27A70218 */  addiu     $a3, $sp, 0x218
/* 48254 8006CE54 00D23021 */  addu      $a2, $a2, $s2
/* 48258 8006CE58 0C01A86C */  jal       func_8006A1B0
/* 4825C 8006CE5C 30C6FFFF */   andi     $a2, $a2, 0xffff
/* 48260 8006CE60 00408021 */  addu      $s0, $v0, $zero
/* 48264 8006CE64 16000072 */  bnez      $s0, .L8006D030
/* 48268 8006CE68 02001021 */   addu     $v0, $s0, $zero
/* 4826C 8006CE6C 97A2021C */  lhu       $v0, 0x21c($sp)
/* 48270 8006CE70 5040000A */  beql      $v0, $zero, .L8006CE9C
/* 48274 8006CE74 A6600000 */   sh       $zero, ($s3)
/* 48278 8006CE78 8FA20218 */  lw        $v0, 0x218($sp)
/* 4827C 8006CE7C 50400007 */  beql      $v0, $zero, .L8006CE9C
/* 48280 8006CE80 A6600000 */   sh       $zero, ($s3)
/* 48284 8006CE84 97A3021E */  lhu       $v1, 0x21e($sp)
/* 48288 8006CE88 96220062 */  lhu       $v0, 0x62($s1)
/* 4828C 8006CE8C 0062102B */  sltu      $v0, $v1, $v0
/* 48290 8006CE90 54400002 */  bnel      $v0, $zero, .L8006CE9C
/* 48294 8006CE94 A6600000 */   sh       $zero, ($s3)
/* 48298 8006CE98 A6630000 */  sh        $v1, ($s3)
.L8006CE9C:
/* 4829C 8006CE9C 8E220050 */  lw        $v0, 0x50($s1)
/* 482A0 8006CEA0 26520001 */  addiu     $s2, $s2, 1
/* 482A4 8006CEA4 0242102A */  slt       $v0, $s2, $v0
/* 482A8 8006CEA8 1440FFE6 */  bnez      $v0, .L8006CE44
/* 482AC 8006CEAC 26730002 */   addiu    $s3, $s3, 2
.L8006CEB0:
/* 482B0 8006CEB0 92220064 */  lbu       $v0, 0x64($s1)
/* 482B4 8006CEB4 10400055 */  beqz      $v0, .L8006D00C
/* 482B8 8006CEB8 00009821 */   addu     $s3, $zero, $zero
/* 482BC 8006CEBC 27B40018 */  addiu     $s4, $sp, 0x18
/* 482C0 8006CEC0 27B60118 */  addiu     $s6, $sp, 0x118
/* 482C4 8006CEC4 27B50238 */  addiu     $s5, $sp, 0x238
/* 482C8 8006CEC8 02202021 */  addu      $a0, $s1, $zero
.L8006CECC:
/* 482CC 8006CECC 27A50118 */  addiu     $a1, $sp, 0x118
/* 482D0 8006CED0 00003021 */  addu      $a2, $zero, $zero
/* 482D4 8006CED4 327200FF */  andi      $s2, $s3, 0xff
/* 482D8 8006CED8 0C01A79B */  jal       func_80069E6C
/* 482DC 8006CEDC 02403821 */   addu     $a3, $s2, $zero
/* 482E0 8006CEE0 00408021 */  addu      $s0, $v0, $zero
/* 482E4 8006CEE4 0010182B */  sltu      $v1, $zero, $s0
/* 482E8 8006CEE8 3A020003 */  xori      $v0, $s0, 3
/* 482EC 8006CEEC 0002102B */  sltu      $v0, $zero, $v0
/* 482F0 8006CEF0 00621824 */  and       $v1, $v1, $v0
/* 482F4 8006CEF4 5460004E */  bnel      $v1, $zero, .L8006D030
/* 482F8 8006CEF8 02001021 */   addu     $v0, $s0, $zero
/* 482FC 8006CEFC 16400002 */  bnez      $s2, .L8006CF08
/* 48300 8006CF00 24050001 */   addiu    $a1, $zero, 1
/* 48304 8006CF04 8E250060 */  lw        $a1, 0x60($s1)
.L8006CF08:
/* 48308 8006CF08 18A0000A */  blez      $a1, .L8006CF34
/* 4830C 8006CF0C 00009021 */   addu     $s2, $zero, $zero
/* 48310 8006CF10 02802021 */  addu      $a0, $s4, $zero
/* 48314 8006CF14 02C01821 */  addu      $v1, $s6, $zero
.L8006CF18:
/* 48318 8006CF18 94620000 */  lhu       $v0, ($v1)
/* 4831C 8006CF1C 24630002 */  addiu     $v1, $v1, 2
/* 48320 8006CF20 26520001 */  addiu     $s2, $s2, 1
/* 48324 8006CF24 A4820000 */  sh        $v0, ($a0)
/* 48328 8006CF28 0245102A */  slt       $v0, $s2, $a1
/* 4832C 8006CF2C 1440FFFA */  bnez      $v0, .L8006CF18
/* 48330 8006CF30 24840002 */   addiu    $a0, $a0, 2
.L8006CF34:
/* 48334 8006CF34 2A420080 */  slti      $v0, $s2, 0x80
/* 48338 8006CF38 10400008 */  beqz      $v0, .L8006CF5C
/* 4833C 8006CF3C 00121040 */   sll      $v0, $s2, 1
/* 48340 8006CF40 24040003 */  addiu     $a0, $zero, 3
/* 48344 8006CF44 00541821 */  addu      $v1, $v0, $s4
.L8006CF48:
/* 48348 8006CF48 A4640000 */  sh        $a0, ($v1)
/* 4834C 8006CF4C 26520001 */  addiu     $s2, $s2, 1
/* 48350 8006CF50 2A420080 */  slti      $v0, $s2, 0x80
/* 48354 8006CF54 1440FFFC */  bnez      $v0, .L8006CF48
/* 48358 8006CF58 24630002 */   addiu    $v1, $v1, 2
.L8006CF5C:
/* 4835C 8006CF5C 8E220050 */  lw        $v0, 0x50($s1)
/* 48360 8006CF60 1840001D */  blez      $v0, .L8006CFD8
/* 48364 8006CF64 00009021 */   addu     $s2, $zero, $zero
/* 48368 8006CF68 326800FF */  andi      $t0, $s3, 0xff
/* 4836C 8006CF6C 00003021 */  addu      $a2, $zero, $zero
/* 48370 8006CF70 02A03821 */  addu      $a3, $s5, $zero
.L8006CF74:
/* 48374 8006CF74 90E20000 */  lbu       $v0, ($a3)
/* 48378 8006CF78 14480011 */  bne       $v0, $t0, .L8006CFC0
/* 4837C 8006CF7C 02A02821 */   addu     $a1, $s5, $zero
.L8006CF80:
/* 48380 8006CF80 00A62021 */  addu      $a0, $a1, $a2
/* 48384 8006CF84 94830000 */  lhu       $v1, ($a0)
/* 48388 8006CF88 96220062 */  lhu       $v0, 0x62($s1)
/* 4838C 8006CF8C 0062182B */  sltu      $v1, $v1, $v0
/* 48390 8006CF90 5460000C */  bnel      $v1, $zero, .L8006CFC4
/* 48394 8006CF94 24C60002 */   addiu    $a2, $a2, 2
/* 48398 8006CF98 90820001 */  lbu       $v0, 1($a0)
/* 4839C 8006CF9C 00021040 */  sll       $v0, $v0, 1
/* 483A0 8006CFA0 00541021 */  addu      $v0, $v0, $s4
/* 483A4 8006CFA4 94430100 */  lhu       $v1, 0x100($v0)
/* 483A8 8006CFA8 A4430000 */  sh        $v1, ($v0)
/* 483AC 8006CFAC 00D41021 */  addu      $v0, $a2, $s4
/* 483B0 8006CFB0 A4430220 */  sh        $v1, 0x220($v0)
/* 483B4 8006CFB4 90820000 */  lbu       $v0, ($a0)
/* 483B8 8006CFB8 1048FFF1 */  beq       $v0, $t0, .L8006CF80
/* 483BC 8006CFBC 00000000 */   nop
.L8006CFC0:
/* 483C0 8006CFC0 24C60002 */  addiu     $a2, $a2, 2
.L8006CFC4:
/* 483C4 8006CFC4 8E220050 */  lw        $v0, 0x50($s1)
/* 483C8 8006CFC8 26520001 */  addiu     $s2, $s2, 1
/* 483CC 8006CFCC 0242102A */  slt       $v0, $s2, $v0
/* 483D0 8006CFD0 1440FFE8 */  bnez      $v0, .L8006CF74
/* 483D4 8006CFD4 24E70002 */   addiu    $a3, $a3, 2
.L8006CFD8:
/* 483D8 8006CFD8 02202021 */  addu      $a0, $s1, $zero
/* 483DC 8006CFDC 27A50018 */  addiu     $a1, $sp, 0x18
/* 483E0 8006CFE0 24060001 */  addiu     $a2, $zero, 1
/* 483E4 8006CFE4 0C01A79B */  jal       func_80069E6C
/* 483E8 8006CFE8 326700FF */   andi     $a3, $s3, 0xff
/* 483EC 8006CFEC 00408021 */  addu      $s0, $v0, $zero
/* 483F0 8006CFF0 1600FF1B */  bnez      $s0, .L8006CC60
/* 483F4 8006CFF4 26730001 */   addiu    $s3, $s3, 1
/* 483F8 8006CFF8 92230064 */  lbu       $v1, 0x64($s1)
/* 483FC 8006CFFC 326200FF */  andi      $v0, $s3, 0xff
/* 48400 8006D000 0043102B */  sltu      $v0, $v0, $v1
/* 48404 8006D004 1440FFB1 */  bnez      $v0, .L8006CECC
/* 48408 8006D008 02202021 */   addu     $a0, $s1, $zero
.L8006D00C:
/* 4840C 8006D00C 13C00004 */  beqz      $fp, .L8006D020
/* 48410 8006D010 2403FFFD */   addiu    $v1, $zero, -3
/* 48414 8006D014 8E220000 */  lw        $v0, ($s1)
/* 48418 8006D018 0801B40A */  j         .L8006D028
/* 4841C 8006D01C 34420002 */   ori      $v0, $v0, 2
.L8006D020:
/* 48420 8006D020 8E220000 */  lw        $v0, ($s1)
/* 48424 8006D024 00431024 */  and       $v0, $v0, $v1
.L8006D028:
/* 48428 8006D028 AE220000 */  sw        $v0, ($s1)
/* 4842C 8006D02C 00001021 */  addu      $v0, $zero, $zero
.L8006D030:
/* 48430 8006D030 8FBF049C */  lw        $ra, 0x49c($sp)
/* 48434 8006D034 8FBE0498 */  lw        $fp, 0x498($sp)
/* 48438 8006D038 8FB70494 */  lw        $s7, 0x494($sp)
/* 4843C 8006D03C 8FB60490 */  lw        $s6, 0x490($sp)
/* 48440 8006D040 8FB5048C */  lw        $s5, 0x48c($sp)
/* 48444 8006D044 8FB40488 */  lw        $s4, 0x488($sp)
/* 48448 8006D048 8FB30484 */  lw        $s3, 0x484($sp)
/* 4844C 8006D04C 8FB20480 */  lw        $s2, 0x480($sp)
/* 48450 8006D050 8FB1047C */  lw        $s1, 0x47c($sp)
/* 48454 8006D054 8FB00478 */  lw        $s0, 0x478($sp)
/* 48458 8006D058 03E00008 */  jr        $ra
/* 4845C 8006D05C 27BD04A0 */   addiu    $sp, $sp, 0x4a0
