.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241578
/* B2D9E8 80241578 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B2D9EC 8024157C AFBF0010 */  sw        $ra, 0x10($sp)
/* B2D9F0 80241580 8C82000C */  lw        $v0, 0xc($a0)
/* B2D9F4 80241584 0C0B1EAF */  jal       get_variable
/* B2D9F8 80241588 8C450000 */   lw       $a1, ($v0)
/* B2D9FC 8024158C 0040182D */  daddu     $v1, $v0, $zero
/* B2DA00 80241590 10600012 */  beqz      $v1, .L802415DC
/* B2DA04 80241594 0000202D */   daddu    $a0, $zero, $zero
/* B2DA08 80241598 8C620000 */  lw        $v0, ($v1)
/* B2DA0C 8024159C 5040000A */  beql      $v0, $zero, .L802415C8
/* B2DA10 802415A0 00041080 */   sll      $v0, $a0, 2
/* B2DA14 802415A4 3C058025 */  lui       $a1, 0x8025
/* B2DA18 802415A8 24A58760 */  addiu     $a1, $a1, -0x78a0
.L802415AC:
/* B2DA1C 802415AC 24630004 */  addiu     $v1, $v1, 4
/* B2DA20 802415B0 24840001 */  addiu     $a0, $a0, 1
/* B2DA24 802415B4 ACA20000 */  sw        $v0, ($a1)
/* B2DA28 802415B8 8C620000 */  lw        $v0, ($v1)
/* B2DA2C 802415BC 1440FFFB */  bnez      $v0, .L802415AC
/* B2DA30 802415C0 24A50004 */   addiu    $a1, $a1, 4
/* B2DA34 802415C4 00041080 */  sll       $v0, $a0, 2
.L802415C8:
/* B2DA38 802415C8 3C018025 */  lui       $at, 0x8025
/* B2DA3C 802415CC 00220821 */  addu      $at, $at, $v0
/* B2DA40 802415D0 AC208760 */  sw        $zero, -0x78a0($at)
/* B2DA44 802415D4 08090581 */  j         .L80241604
/* B2DA48 802415D8 00000000 */   nop      
.L802415DC:
/* B2DA4C 802415DC 3C038025 */  lui       $v1, 0x8025
/* B2DA50 802415E0 24638760 */  addiu     $v1, $v1, -0x78a0
/* B2DA54 802415E4 0060282D */  daddu     $a1, $v1, $zero
.L802415E8:
/* B2DA58 802415E8 24820010 */  addiu     $v0, $a0, 0x10
/* B2DA5C 802415EC AC620000 */  sw        $v0, ($v1)
/* B2DA60 802415F0 24630004 */  addiu     $v1, $v1, 4
/* B2DA64 802415F4 24840001 */  addiu     $a0, $a0, 1
/* B2DA68 802415F8 28820070 */  slti      $v0, $a0, 0x70
/* B2DA6C 802415FC 1440FFFA */  bnez      $v0, .L802415E8
/* B2DA70 80241600 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80241604:
/* B2DA74 80241604 8FBF0010 */  lw        $ra, 0x10($sp)
/* B2DA78 80241608 24020002 */  addiu     $v0, $zero, 2
/* B2DA7C 8024160C 03E00008 */  jr        $ra
/* B2DA80 80241610 27BD0018 */   addiu    $sp, $sp, 0x18
