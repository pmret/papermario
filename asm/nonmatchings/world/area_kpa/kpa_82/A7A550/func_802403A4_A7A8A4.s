.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403A4_A7A8A4
/* A7A8A4 802403A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A7A8A8 802403A8 AFBF0010 */  sw        $ra, 0x10($sp)
/* A7A8AC 802403AC 8C82000C */  lw        $v0, 0xc($a0)
/* A7A8B0 802403B0 0C0B1EAF */  jal       get_variable
/* A7A8B4 802403B4 8C450000 */   lw       $a1, ($v0)
/* A7A8B8 802403B8 0040182D */  daddu     $v1, $v0, $zero
/* A7A8BC 802403BC 10600012 */  beqz      $v1, .L80240408
/* A7A8C0 802403C0 0000202D */   daddu    $a0, $zero, $zero
/* A7A8C4 802403C4 8C620000 */  lw        $v0, ($v1)
/* A7A8C8 802403C8 5040000A */  beql      $v0, $zero, .L802403F4
/* A7A8CC 802403CC 00041080 */   sll      $v0, $a0, 2
/* A7A8D0 802403D0 3C058025 */  lui       $a1, %hi(D_80249158)
/* A7A8D4 802403D4 24A59158 */  addiu     $a1, $a1, %lo(D_80249158)
.L802403D8:
/* A7A8D8 802403D8 24630004 */  addiu     $v1, $v1, 4
/* A7A8DC 802403DC 24840001 */  addiu     $a0, $a0, 1
/* A7A8E0 802403E0 ACA20000 */  sw        $v0, ($a1)
/* A7A8E4 802403E4 8C620000 */  lw        $v0, ($v1)
/* A7A8E8 802403E8 1440FFFB */  bnez      $v0, .L802403D8
/* A7A8EC 802403EC 24A50004 */   addiu    $a1, $a1, 4
/* A7A8F0 802403F0 00041080 */  sll       $v0, $a0, 2
.L802403F4:
/* A7A8F4 802403F4 3C018025 */  lui       $at, %hi(D_80249158)
/* A7A8F8 802403F8 00220821 */  addu      $at, $at, $v0
/* A7A8FC 802403FC AC209158 */  sw        $zero, %lo(D_80249158)($at)
/* A7A900 80240400 0809010C */  j         .L80240430
/* A7A904 80240404 00000000 */   nop      
.L80240408:
/* A7A908 80240408 3C038025 */  lui       $v1, %hi(D_80249158)
/* A7A90C 8024040C 24639158 */  addiu     $v1, $v1, %lo(D_80249158)
/* A7A910 80240410 0060282D */  daddu     $a1, $v1, $zero
.L80240414:
/* A7A914 80240414 24820080 */  addiu     $v0, $a0, 0x80
/* A7A918 80240418 AC620000 */  sw        $v0, ($v1)
/* A7A91C 8024041C 24630004 */  addiu     $v1, $v1, 4
/* A7A920 80240420 24840001 */  addiu     $a0, $a0, 1
/* A7A924 80240424 2882005B */  slti      $v0, $a0, 0x5b
/* A7A928 80240428 1440FFFA */  bnez      $v0, .L80240414
/* A7A92C 8024042C ACA0016C */   sw       $zero, 0x16c($a1)
.L80240430:
/* A7A930 80240430 8FBF0010 */  lw        $ra, 0x10($sp)
/* A7A934 80240434 24020002 */  addiu     $v0, $zero, 2
/* A7A938 80240438 03E00008 */  jr        $ra
/* A7A93C 8024043C 27BD0018 */   addiu    $sp, $sp, 0x18
