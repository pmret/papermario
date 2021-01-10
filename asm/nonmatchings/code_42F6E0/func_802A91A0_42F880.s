.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A91A0_42F880
/* 42F880 802A91A0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 42F884 802A91A4 AFB20018 */  sw        $s2, 0x18($sp)
/* 42F888 802A91A8 0080902D */  daddu     $s2, $a0, $zero
/* 42F88C 802A91AC AFB10014 */  sw        $s1, 0x14($sp)
/* 42F890 802A91B0 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42F894 802A91B4 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42F898 802A91B8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 42F89C 802A91BC 3C13800E */  lui       $s3, %hi(gBattleStatus)
/* 42F8A0 802A91C0 2673C070 */  addiu     $s3, $s3, %lo(gBattleStatus)
/* 42F8A4 802A91C4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 42F8A8 802A91C8 AFB00010 */  sw        $s0, 0x10($sp)
/* 42F8AC 802A91CC 82620083 */  lb        $v0, 0x83($s3)
/* 42F8B0 802A91D0 8E50000C */  lw        $s0, 0xc($s2)
/* 42F8B4 802A91D4 10400029 */  beqz      $v0, .L802A927C
/* 42F8B8 802A91D8 0260182D */   daddu    $v1, $s3, $zero
/* 42F8BC 802A91DC 0C09A216 */  jal       func_80268858
/* 42F8C0 802A91E0 00000000 */   nop      
/* 42F8C4 802A91E4 8E050000 */  lw        $a1, ($s0)
/* 42F8C8 802A91E8 26100004 */  addiu     $s0, $s0, 4
/* 42F8CC 802A91EC 0C0B1EAF */  jal       get_variable
/* 42F8D0 802A91F0 0240202D */   daddu    $a0, $s2, $zero
/* 42F8D4 802A91F4 A622004E */  sh        $v0, 0x4e($s1)
/* 42F8D8 802A91F8 8E050000 */  lw        $a1, ($s0)
/* 42F8DC 802A91FC 26100004 */  addiu     $s0, $s0, 4
/* 42F8E0 802A9200 0C0B1EAF */  jal       get_variable
/* 42F8E4 802A9204 0240202D */   daddu    $a0, $s2, $zero
/* 42F8E8 802A9208 A6220052 */  sh        $v0, 0x52($s1)
/* 42F8EC 802A920C 8E050000 */  lw        $a1, ($s0)
/* 42F8F0 802A9210 26100004 */  addiu     $s0, $s0, 4
/* 42F8F4 802A9214 0C0B1EAF */  jal       get_variable
/* 42F8F8 802A9218 0240202D */   daddu    $a0, $s2, $zero
/* 42F8FC 802A921C 00022400 */  sll       $a0, $v0, 0x10
/* 42F900 802A9220 00042403 */  sra       $a0, $a0, 0x10
/* 42F904 802A9224 0C09A089 */  jal       func_80268224
/* 42F908 802A9228 A6220050 */   sh       $v0, 0x50($s1)
/* 42F90C 802A922C A6220050 */  sh        $v0, 0x50($s1)
/* 42F910 802A9230 8E050000 */  lw        $a1, ($s0)
/* 42F914 802A9234 0C0B1EAF */  jal       get_variable
/* 42F918 802A9238 0240202D */   daddu    $a0, $s2, $zero
/* 42F91C 802A923C 3C04FFFF */  lui       $a0, 0xffff
/* 42F920 802A9240 34847FFF */  ori       $a0, $a0, 0x7fff
/* 42F924 802A9244 A6220064 */  sh        $v0, 0x64($s1)
/* 42F928 802A9248 A2200060 */  sb        $zero, 0x60($s1)
/* 42F92C 802A924C A6200044 */  sh        $zero, 0x44($s1)
/* 42F930 802A9250 A6200048 */  sh        $zero, 0x48($s1)
/* 42F934 802A9254 8E620000 */  lw        $v0, ($s3)
/* 42F938 802A9258 2403000A */  addiu     $v1, $zero, 0xa
/* 42F93C 802A925C A2600081 */  sb        $zero, 0x81($s3)
/* 42F940 802A9260 A2600086 */  sb        $zero, 0x86($s3)
/* 42F944 802A9264 A623004C */  sh        $v1, 0x4c($s1)
/* 42F948 802A9268 00441024 */  and       $v0, $v0, $a0
/* 42F94C 802A926C 0C09A446 */  jal       func_80269118
/* 42F950 802A9270 AE620000 */   sw       $v0, ($s3)
/* 42F954 802A9274 080AA4A1 */  j         .L802A9284
/* 42F958 802A9278 24020002 */   addiu    $v0, $zero, 2
.L802A927C:
/* 42F95C 802A927C A0600081 */  sb        $zero, 0x81($v1)
/* 42F960 802A9280 24020002 */  addiu     $v0, $zero, 2
.L802A9284:
/* 42F964 802A9284 8FBF0020 */  lw        $ra, 0x20($sp)
/* 42F968 802A9288 8FB3001C */  lw        $s3, 0x1c($sp)
/* 42F96C 802A928C 8FB20018 */  lw        $s2, 0x18($sp)
/* 42F970 802A9290 8FB10014 */  lw        $s1, 0x14($sp)
/* 42F974 802A9294 8FB00010 */  lw        $s0, 0x10($sp)
/* 42F978 802A9298 03E00008 */  jr        $ra
/* 42F97C 802A929C 27BD0028 */   addiu    $sp, $sp, 0x28
