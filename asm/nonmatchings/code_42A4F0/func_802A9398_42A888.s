.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9398_42A888
/* 42A888 802A9398 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 42A88C 802A939C AFB3001C */  sw        $s3, 0x1c($sp)
/* 42A890 802A93A0 0080982D */  daddu     $s3, $a0, $zero
/* 42A894 802A93A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 42A898 802A93A8 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42A89C 802A93AC 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42A8A0 802A93B0 AFB20018 */  sw        $s2, 0x18($sp)
/* 42A8A4 802A93B4 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 42A8A8 802A93B8 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 42A8AC 802A93BC AFBF0020 */  sw        $ra, 0x20($sp)
/* 42A8B0 802A93C0 AFB00010 */  sw        $s0, 0x10($sp)
/* 42A8B4 802A93C4 82420083 */  lb        $v0, 0x83($s2)
/* 42A8B8 802A93C8 8E70000C */  lw        $s0, 0xc($s3)
/* 42A8BC 802A93CC 10400026 */  beqz      $v0, .L802A9468
/* 42A8C0 802A93D0 0240182D */   daddu    $v1, $s2, $zero
/* 42A8C4 802A93D4 0C09A216 */  jal       func_80268858
/* 42A8C8 802A93D8 00000000 */   nop      
/* 42A8CC 802A93DC 8E050000 */  lw        $a1, ($s0)
/* 42A8D0 802A93E0 26100004 */  addiu     $s0, $s0, 4
/* 42A8D4 802A93E4 0C0B1EAF */  jal       get_variable
/* 42A8D8 802A93E8 0260202D */   daddu    $a0, $s3, $zero
/* 42A8DC 802A93EC A622004E */  sh        $v0, 0x4e($s1)
/* 42A8E0 802A93F0 8E050000 */  lw        $a1, ($s0)
/* 42A8E4 802A93F4 26100004 */  addiu     $s0, $s0, 4
/* 42A8E8 802A93F8 0C0B1EAF */  jal       get_variable
/* 42A8EC 802A93FC 0260202D */   daddu    $a0, $s3, $zero
/* 42A8F0 802A9400 A6220052 */  sh        $v0, 0x52($s1)
/* 42A8F4 802A9404 8E050000 */  lw        $a1, ($s0)
/* 42A8F8 802A9408 0C0B1EAF */  jal       get_variable
/* 42A8FC 802A940C 0260202D */   daddu    $a0, $s3, $zero
/* 42A900 802A9410 00022400 */  sll       $a0, $v0, 0x10
/* 42A904 802A9414 00042403 */  sra       $a0, $a0, 0x10
/* 42A908 802A9418 0C09A089 */  jal       func_80268224
/* 42A90C 802A941C A6220050 */   sh       $v0, 0x50($s1)
/* 42A910 802A9420 3C04FFFF */  lui       $a0, 0xffff
/* 42A914 802A9424 34847FFF */  ori       $a0, $a0, 0x7fff
/* 42A918 802A9428 A6220050 */  sh        $v0, 0x50($s1)
/* 42A91C 802A942C 24020001 */  addiu     $v0, $zero, 1
/* 42A920 802A9430 A2200060 */  sb        $zero, 0x60($s1)
/* 42A924 802A9434 A6200044 */  sh        $zero, 0x44($s1)
/* 42A928 802A9438 A6200048 */  sh        $zero, 0x48($s1)
/* 42A92C 802A943C A2420084 */  sb        $v0, 0x84($s2)
/* 42A930 802A9440 8E420000 */  lw        $v0, ($s2)
/* 42A934 802A9444 2403000A */  addiu     $v1, $zero, 0xa
/* 42A938 802A9448 A2400081 */  sb        $zero, 0x81($s2)
/* 42A93C 802A944C A2400086 */  sb        $zero, 0x86($s2)
/* 42A940 802A9450 A623004C */  sh        $v1, 0x4c($s1)
/* 42A944 802A9454 00441024 */  and       $v0, $v0, $a0
/* 42A948 802A9458 0C09A446 */  jal       func_80269118
/* 42A94C 802A945C AE420000 */   sw       $v0, ($s2)
/* 42A950 802A9460 080AA51C */  j         .L802A9470
/* 42A954 802A9464 24020002 */   addiu    $v0, $zero, 2
.L802A9468:
/* 42A958 802A9468 A0600081 */  sb        $zero, 0x81($v1)
/* 42A95C 802A946C 24020002 */  addiu     $v0, $zero, 2
.L802A9470:
/* 42A960 802A9470 8FBF0020 */  lw        $ra, 0x20($sp)
/* 42A964 802A9474 8FB3001C */  lw        $s3, 0x1c($sp)
/* 42A968 802A9478 8FB20018 */  lw        $s2, 0x18($sp)
/* 42A96C 802A947C 8FB10014 */  lw        $s1, 0x14($sp)
/* 42A970 802A9480 8FB00010 */  lw        $s0, 0x10($sp)
/* 42A974 802A9484 03E00008 */  jr        $ra
/* 42A978 802A9488 27BD0028 */   addiu    $sp, $sp, 0x28
