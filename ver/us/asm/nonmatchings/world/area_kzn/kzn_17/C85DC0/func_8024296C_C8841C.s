.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024296C_C8841C
/* C8841C 8024296C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C88420 80242970 AFBF0010 */  sw        $ra, 0x10($sp)
/* C88424 80242974 8C82000C */  lw        $v0, 0xc($a0)
/* C88428 80242978 0C0B1EAF */  jal       evt_get_variable
/* C8842C 8024297C 8C450000 */   lw       $a1, ($v0)
/* C88430 80242980 0040182D */  daddu     $v1, $v0, $zero
/* C88434 80242984 10600012 */  beqz      $v1, .L802429D0
/* C88438 80242988 0000202D */   daddu    $a0, $zero, $zero
/* C8843C 8024298C 8C620000 */  lw        $v0, ($v1)
/* C88440 80242990 5040000A */  beql      $v0, $zero, .L802429BC
/* C88444 80242994 00041080 */   sll      $v0, $a0, 2
/* C88448 80242998 3C058024 */  lui       $a1, %hi(D_802465F0)
/* C8844C 8024299C 24A565F0 */  addiu     $a1, $a1, %lo(D_802465F0)
.L802429A0:
/* C88450 802429A0 24630004 */  addiu     $v1, $v1, 4
/* C88454 802429A4 24840001 */  addiu     $a0, $a0, 1
/* C88458 802429A8 ACA20000 */  sw        $v0, ($a1)
/* C8845C 802429AC 8C620000 */  lw        $v0, ($v1)
/* C88460 802429B0 1440FFFB */  bnez      $v0, .L802429A0
/* C88464 802429B4 24A50004 */   addiu    $a1, $a1, 4
/* C88468 802429B8 00041080 */  sll       $v0, $a0, 2
.L802429BC:
/* C8846C 802429BC 3C018024 */  lui       $at, %hi(D_802465F0)
/* C88470 802429C0 00220821 */  addu      $at, $at, $v0
/* C88474 802429C4 AC2065F0 */  sw        $zero, %lo(D_802465F0)($at)
/* C88478 802429C8 08090A7E */  j         .L802429F8
/* C8847C 802429CC 00000000 */   nop
.L802429D0:
/* C88480 802429D0 3C038024 */  lui       $v1, %hi(D_802465F0)
/* C88484 802429D4 246365F0 */  addiu     $v1, $v1, %lo(D_802465F0)
/* C88488 802429D8 0060282D */  daddu     $a1, $v1, $zero
.L802429DC:
/* C8848C 802429DC 24820010 */  addiu     $v0, $a0, 0x10
/* C88490 802429E0 AC620000 */  sw        $v0, ($v1)
/* C88494 802429E4 24630004 */  addiu     $v1, $v1, 4
/* C88498 802429E8 24840001 */  addiu     $a0, $a0, 1
/* C8849C 802429EC 28820070 */  slti      $v0, $a0, 0x70
/* C884A0 802429F0 1440FFFA */  bnez      $v0, .L802429DC
/* C884A4 802429F4 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L802429F8:
/* C884A8 802429F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* C884AC 802429FC 24020002 */  addiu     $v0, $zero, 2
/* C884B0 80242A00 03E00008 */  jr        $ra
/* C884B4 80242A04 27BD0018 */   addiu    $sp, $sp, 0x18
