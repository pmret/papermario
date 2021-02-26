.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004BD94
/* 27194 8004BD94 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 27198 8004BD98 AFBF0010 */  sw        $ra, 0x10($sp)
/* 2719C 8004BD9C 908200C0 */  lbu       $v0, 0xc0($a0)
/* 271A0 8004BDA0 1440005A */  bnez      $v0, .L8004BF0C
/* 271A4 8004BDA4 00000000 */   nop
/* 271A8 8004BDA8 ACA60000 */  sw        $a2, ($a1)
/* 271AC 8004BDAC ACA60050 */  sw        $a2, 0x50($a1)
/* 271B0 8004BDB0 8C820000 */  lw        $v0, ($a0)
/* 271B4 8004BDB4 3C047FFF */  lui       $a0, 0x7fff
/* 271B8 8004BDB8 24060001 */  addiu     $a2, $zero, 1
/* 271BC 8004BDBC 8C430004 */  lw        $v1, 4($v0)
/* 271C0 8004BDC0 24020040 */  addiu     $v0, $zero, 0x40
/* 271C4 8004BDC4 A0A2009B */  sb        $v0, 0x9b($a1)
/* 271C8 8004BDC8 24027FFF */  addiu     $v0, $zero, 0x7fff
/* 271CC 8004BDCC A4A2005C */  sh        $v0, 0x5c($a1)
/* 271D0 8004BDD0 A4A2005E */  sh        $v0, 0x5e($a1)
/* 271D4 8004BDD4 2402007F */  addiu     $v0, $zero, 0x7f
/* 271D8 8004BDD8 A0A0009C */  sb        $zero, 0x9c($a1)
/* 271DC 8004BDDC A0A0009D */  sb        $zero, 0x9d($a1)
/* 271E0 8004BDE0 A0A0009E */  sb        $zero, 0x9e($a1)
/* 271E4 8004BDE4 A0A2009F */  sb        $v0, 0x9f($a1)
/* 271E8 8004BDE8 A4A00092 */  sh        $zero, 0x92($a1)
/* 271EC 8004BDEC A0A00094 */  sb        $zero, 0x94($a1)
/* 271F0 8004BDF0 ACA00088 */  sw        $zero, 0x88($a1)
/* 271F4 8004BDF4 A0A0008C */  sb        $zero, 0x8c($a1)
/* 271F8 8004BDF8 A4A6008E */  sh        $a2, 0x8e($a1)
/* 271FC 8004BDFC A4A00090 */  sh        $zero, 0x90($a1)
/* 27200 8004BE00 ACA3001C */  sw        $v1, 0x1c($a1)
/* 27204 8004BE04 94E30000 */  lhu       $v1, ($a3)
/* 27208 8004BE08 8FA20028 */  lw        $v0, 0x28($sp)
/* 2720C 8004BE0C 3484FFFF */  ori       $a0, $a0, 0xffff
/* 27210 8004BE10 A0A20098 */  sb        $v0, 0x98($a1)
/* 27214 8004BE14 8FA2002C */  lw        $v0, 0x2c($sp)
/* 27218 8004BE18 306323FF */  andi      $v1, $v1, 0x23ff
/* 2721C 8004BE1C ACA00018 */  sw        $zero, 0x18($a1)
/* 27220 8004BE20 ACA00054 */  sw        $zero, 0x54($a1)
/* 27224 8004BE24 A0A000A0 */  sb        $zero, 0xa0($a1)
/* 27228 8004BE28 A0A000A1 */  sb        $zero, 0xa1($a1)
/* 2722C 8004BE2C A0A000A2 */  sb        $zero, 0xa2($a1)
/* 27230 8004BE30 A0A000A3 */  sb        $zero, 0xa3($a1)
/* 27234 8004BE34 ACA4006C */  sw        $a0, 0x6c($a1)
/* 27238 8004BE38 A4A00074 */  sh        $zero, 0x74($a1)
/* 2723C 8004BE3C ACA00070 */  sw        $zero, 0x70($a1)
/* 27240 8004BE40 A4A00076 */  sh        $zero, 0x76($a1)
/* 27244 8004BE44 A0A20099 */  sb        $v0, 0x99($a1)
/* 27248 8004BE48 ACA00060 */  sw        $zero, 0x60($a1)
/* 2724C 8004BE4C A4A30096 */  sh        $v1, 0x96($a1)
/* 27250 8004BE50 A4A00068 */  sh        $zero, 0x68($a1)
/* 27254 8004BE54 8CA30000 */  lw        $v1, ($a1)
/* 27258 8004BE58 ACA00064 */  sw        $zero, 0x64($a1)
/* 2725C 8004BE5C A4A0006A */  sh        $zero, 0x6a($a1)
/* 27260 8004BE60 ACA00080 */  sw        $zero, 0x80($a1)
/* 27264 8004BE64 A0A00084 */  sb        $zero, 0x84($a1)
/* 27268 8004BE68 A0A00085 */  sb        $zero, 0x85($a1)
/* 2726C 8004BE6C 90620000 */  lbu       $v0, ($v1)
/* 27270 8004BE70 24630001 */  addiu     $v1, $v1, 1
/* 27274 8004BE74 ACA30000 */  sw        $v1, ($a1)
/* 27278 8004BE78 A0A2009A */  sb        $v0, 0x9a($a1)
/* 2727C 8004BE7C 0040202D */  daddu     $a0, $v0, $zero
/* 27280 8004BE80 30430003 */  andi      $v1, $v0, 3
/* 27284 8004BE84 24020001 */  addiu     $v0, $zero, 1
/* 27288 8004BE88 1062000B */  beq       $v1, $v0, .L8004BEB8
/* 2728C 8004BE8C 28620002 */   slti     $v0, $v1, 2
/* 27290 8004BE90 10400005 */  beqz      $v0, .L8004BEA8
/* 27294 8004BE94 24020002 */   addiu    $v0, $zero, 2
/* 27298 8004BE98 10600007 */  beqz      $v1, .L8004BEB8
/* 2729C 8004BE9C 00A0202D */   daddu    $a0, $a1, $zero
/* 272A0 8004BEA0 08012FC1 */  j         .L8004BF04
/* 272A4 8004BEA4 00000000 */   nop
.L8004BEA8:
/* 272A8 8004BEA8 10620005 */  beq       $v1, $v0, .L8004BEC0
/* 272AC 8004BEAC 308200FC */   andi     $v0, $a0, 0xfc
/* 272B0 8004BEB0 08012FC1 */  j         .L8004BF04
/* 272B4 8004BEB4 00A0202D */   daddu    $a0, $a1, $zero
.L8004BEB8:
/* 272B8 8004BEB8 08012FC0 */  j         .L8004BF00
/* 272BC 8004BEBC A0A600A9 */   sb       $a2, 0xa9($a1)
.L8004BEC0:
/* 272C0 8004BEC0 8CA30000 */  lw        $v1, ($a1)
/* 272C4 8004BEC4 A0A2009A */  sb        $v0, 0x9a($a1)
/* 272C8 8004BEC8 A0A600A9 */  sb        $a2, 0xa9($a1)
/* 272CC 8004BECC 90620000 */  lbu       $v0, ($v1)
/* 272D0 8004BED0 A0A20078 */  sb        $v0, 0x78($a1)
/* 272D4 8004BED4 90620001 */  lbu       $v0, 1($v1)
/* 272D8 8004BED8 A0A20079 */  sb        $v0, 0x79($a1)
/* 272DC 8004BEDC 90620002 */  lbu       $v0, 2($v1)
/* 272E0 8004BEE0 00021042 */  srl       $v0, $v0, 1
/* 272E4 8004BEE4 34420003 */  ori       $v0, $v0, 3
/* 272E8 8004BEE8 A0A2007A */  sb        $v0, 0x7a($a1)
/* 272EC 8004BEEC 90620002 */  lbu       $v0, 2($v1)
/* 272F0 8004BEF0 24A30078 */  addiu     $v1, $a1, 0x78
/* 272F4 8004BEF4 ACA30000 */  sw        $v1, ($a1)
/* 272F8 8004BEF8 30420007 */  andi      $v0, $v0, 7
/* 272FC 8004BEFC A0A2007E */  sb        $v0, 0x7e($a1)
.L8004BF00:
/* 27300 8004BF00 00A0202D */  daddu     $a0, $a1, $zero
.L8004BF04:
/* 27304 8004BF04 0C013021 */  jal       func_8004C084
/* 27308 8004BF08 00E0282D */   daddu    $a1, $a3, $zero
.L8004BF0C:
/* 2730C 8004BF0C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 27310 8004BF10 03E00008 */  jr        $ra
/* 27314 8004BF14 27BD0018 */   addiu    $sp, $sp, 0x18
