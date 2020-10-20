.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403A4
/* A78864 802403A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A78868 802403A8 AFBF0010 */  sw        $ra, 0x10($sp)
/* A7886C 802403AC 8C82000C */  lw        $v0, 0xc($a0)
/* A78870 802403B0 0C0B1EAF */  jal       get_variable
/* A78874 802403B4 8C450000 */   lw       $a1, ($v0)
/* A78878 802403B8 0040182D */  daddu     $v1, $v0, $zero
/* A7887C 802403BC 10600012 */  beqz      $v1, .L80240408
/* A78880 802403C0 0000202D */   daddu    $a0, $zero, $zero
/* A78884 802403C4 8C620000 */  lw        $v0, ($v1)
/* A78888 802403C8 5040000A */  beql      $v0, $zero, .L802403F4
/* A7888C 802403CC 00041080 */   sll      $v0, $a0, 2
/* A78890 802403D0 3C058024 */  lui       $a1, 0x8024
/* A78894 802403D4 24A52208 */  addiu     $a1, $a1, 0x2208
.L802403D8:
/* A78898 802403D8 24630004 */  addiu     $v1, $v1, 4
/* A7889C 802403DC 24840001 */  addiu     $a0, $a0, 1
/* A788A0 802403E0 ACA20000 */  sw        $v0, ($a1)
/* A788A4 802403E4 8C620000 */  lw        $v0, ($v1)
/* A788A8 802403E8 1440FFFB */  bnez      $v0, .L802403D8
/* A788AC 802403EC 24A50004 */   addiu    $a1, $a1, 4
/* A788B0 802403F0 00041080 */  sll       $v0, $a0, 2
.L802403F4:
/* A788B4 802403F4 3C018024 */  lui       $at, 0x8024
/* A788B8 802403F8 00220821 */  addu      $at, $at, $v0
/* A788BC 802403FC AC202208 */  sw        $zero, 0x2208($at)
/* A788C0 80240400 0809010C */  j         .L80240430
/* A788C4 80240404 00000000 */   nop      
.L80240408:
/* A788C8 80240408 3C038024 */  lui       $v1, 0x8024
/* A788CC 8024040C 24632208 */  addiu     $v1, $v1, 0x2208
/* A788D0 80240410 0060282D */  daddu     $a1, $v1, $zero
.L80240414:
/* A788D4 80240414 24820080 */  addiu     $v0, $a0, 0x80
/* A788D8 80240418 AC620000 */  sw        $v0, ($v1)
/* A788DC 8024041C 24630004 */  addiu     $v1, $v1, 4
/* A788E0 80240420 24840001 */  addiu     $a0, $a0, 1
/* A788E4 80240424 2882005B */  slti      $v0, $a0, 0x5b
/* A788E8 80240428 1440FFFA */  bnez      $v0, .L80240414
/* A788EC 8024042C ACA0016C */   sw       $zero, 0x16c($a1)
.L80240430:
/* A788F0 80240430 8FBF0010 */  lw        $ra, 0x10($sp)
/* A788F4 80240434 24020002 */  addiu     $v0, $zero, 2
/* A788F8 80240438 03E00008 */  jr        $ra
/* A788FC 8024043C 27BD0018 */   addiu    $sp, $sp, 0x18
