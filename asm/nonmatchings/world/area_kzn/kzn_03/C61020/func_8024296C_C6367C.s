.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024296C_C6367C
/* C6367C 8024296C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C63680 80242970 AFBF0010 */  sw        $ra, 0x10($sp)
/* C63684 80242974 8C82000C */  lw        $v0, 0xc($a0)
/* C63688 80242978 0C0B1EAF */  jal       get_variable
/* C6368C 8024297C 8C450000 */   lw       $a1, ($v0)
/* C63690 80242980 0040182D */  daddu     $v1, $v0, $zero
/* C63694 80242984 10600012 */  beqz      $v1, .L802429D0
/* C63698 80242988 0000202D */   daddu    $a0, $zero, $zero
/* C6369C 8024298C 8C620000 */  lw        $v0, ($v1)
/* C636A0 80242990 5040000A */  beql      $v0, $zero, .L802429BC
/* C636A4 80242994 00041080 */   sll      $v0, $a0, 2
/* C636A8 80242998 3C058024 */  lui       $a1, %hi(D_80247420)
/* C636AC 8024299C 24A57420 */  addiu     $a1, $a1, %lo(D_80247420)
.L802429A0:
/* C636B0 802429A0 24630004 */  addiu     $v1, $v1, 4
/* C636B4 802429A4 24840001 */  addiu     $a0, $a0, 1
/* C636B8 802429A8 ACA20000 */  sw        $v0, ($a1)
/* C636BC 802429AC 8C620000 */  lw        $v0, ($v1)
/* C636C0 802429B0 1440FFFB */  bnez      $v0, .L802429A0
/* C636C4 802429B4 24A50004 */   addiu    $a1, $a1, 4
/* C636C8 802429B8 00041080 */  sll       $v0, $a0, 2
.L802429BC:
/* C636CC 802429BC 3C018024 */  lui       $at, %hi(D_80247420)
/* C636D0 802429C0 00220821 */  addu      $at, $at, $v0
/* C636D4 802429C4 AC207420 */  sw        $zero, %lo(D_80247420)($at)
/* C636D8 802429C8 08090A7E */  j         .L802429F8
/* C636DC 802429CC 00000000 */   nop      
.L802429D0:
/* C636E0 802429D0 3C038024 */  lui       $v1, %hi(D_80247420)
/* C636E4 802429D4 24637420 */  addiu     $v1, $v1, %lo(D_80247420)
/* C636E8 802429D8 0060282D */  daddu     $a1, $v1, $zero
.L802429DC:
/* C636EC 802429DC 24820010 */  addiu     $v0, $a0, 0x10
/* C636F0 802429E0 AC620000 */  sw        $v0, ($v1)
/* C636F4 802429E4 24630004 */  addiu     $v1, $v1, 4
/* C636F8 802429E8 24840001 */  addiu     $a0, $a0, 1
/* C636FC 802429EC 28820070 */  slti      $v0, $a0, 0x70
/* C63700 802429F0 1440FFFA */  bnez      $v0, .L802429DC
/* C63704 802429F4 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L802429F8:
/* C63708 802429F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* C6370C 802429FC 24020002 */  addiu     $v0, $zero, 2
/* C63710 80242A00 03E00008 */  jr        $ra
/* C63714 80242A04 27BD0018 */   addiu    $sp, $sp, 0x18
