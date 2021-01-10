.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9138_42C828
/* 42C828 802A9138 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 42C82C 802A913C AFB3001C */  sw        $s3, 0x1c($sp)
/* 42C830 802A9140 0080982D */  daddu     $s3, $a0, $zero
/* 42C834 802A9144 AFB10014 */  sw        $s1, 0x14($sp)
/* 42C838 802A9148 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42C83C 802A914C 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42C840 802A9150 AFB20018 */  sw        $s2, 0x18($sp)
/* 42C844 802A9154 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 42C848 802A9158 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 42C84C 802A915C AFBF0020 */  sw        $ra, 0x20($sp)
/* 42C850 802A9160 AFB00010 */  sw        $s0, 0x10($sp)
/* 42C854 802A9164 82420083 */  lb        $v0, 0x83($s2)
/* 42C858 802A9168 8E70000C */  lw        $s0, 0xc($s3)
/* 42C85C 802A916C 10400025 */  beqz      $v0, .L802A9204
/* 42C860 802A9170 0240182D */   daddu    $v1, $s2, $zero
/* 42C864 802A9174 0C09A216 */  jal       func_80268858
/* 42C868 802A9178 00000000 */   nop      
/* 42C86C 802A917C 8E050000 */  lw        $a1, ($s0)
/* 42C870 802A9180 26100004 */  addiu     $s0, $s0, 4
/* 42C874 802A9184 0C0B1EAF */  jal       get_variable
/* 42C878 802A9188 0260202D */   daddu    $a0, $s3, $zero
/* 42C87C 802A918C A622004E */  sh        $v0, 0x4e($s1)
/* 42C880 802A9190 8E050000 */  lw        $a1, ($s0)
/* 42C884 802A9194 26100004 */  addiu     $s0, $s0, 4
/* 42C888 802A9198 0C0B1EAF */  jal       get_variable
/* 42C88C 802A919C 0260202D */   daddu    $a0, $s3, $zero
/* 42C890 802A91A0 A6220052 */  sh        $v0, 0x52($s1)
/* 42C894 802A91A4 8E050000 */  lw        $a1, ($s0)
/* 42C898 802A91A8 0C0B1EAF */  jal       get_variable
/* 42C89C 802A91AC 0260202D */   daddu    $a0, $s3, $zero
/* 42C8A0 802A91B0 00022400 */  sll       $a0, $v0, 0x10
/* 42C8A4 802A91B4 00042403 */  sra       $a0, $a0, 0x10
/* 42C8A8 802A91B8 0C09A089 */  jal       func_80268224
/* 42C8AC 802A91BC A6220050 */   sh       $v0, 0x50($s1)
/* 42C8B0 802A91C0 3C04FFFF */  lui       $a0, 0xffff
/* 42C8B4 802A91C4 34847FFF */  ori       $a0, $a0, 0x7fff
/* 42C8B8 802A91C8 A6220050 */  sh        $v0, 0x50($s1)
/* 42C8BC 802A91CC A2200060 */  sb        $zero, 0x60($s1)
/* 42C8C0 802A91D0 A6200044 */  sh        $zero, 0x44($s1)
/* 42C8C4 802A91D4 A6200048 */  sh        $zero, 0x48($s1)
/* 42C8C8 802A91D8 8E420000 */  lw        $v0, ($s2)
/* 42C8CC 802A91DC 2403000A */  addiu     $v1, $zero, 0xa
/* 42C8D0 802A91E0 A2400081 */  sb        $zero, 0x81($s2)
/* 42C8D4 802A91E4 A2400084 */  sb        $zero, 0x84($s2)
/* 42C8D8 802A91E8 A2400086 */  sb        $zero, 0x86($s2)
/* 42C8DC 802A91EC A623004C */  sh        $v1, 0x4c($s1)
/* 42C8E0 802A91F0 00441024 */  and       $v0, $v0, $a0
/* 42C8E4 802A91F4 0C09A446 */  jal       func_80269118
/* 42C8E8 802A91F8 AE420000 */   sw       $v0, ($s2)
/* 42C8EC 802A91FC 080AA483 */  j         .L802A920C
/* 42C8F0 802A9200 24020002 */   addiu    $v0, $zero, 2
.L802A9204:
/* 42C8F4 802A9204 A0600081 */  sb        $zero, 0x81($v1)
/* 42C8F8 802A9208 24020002 */  addiu     $v0, $zero, 2
.L802A920C:
/* 42C8FC 802A920C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 42C900 802A9210 8FB3001C */  lw        $s3, 0x1c($sp)
/* 42C904 802A9214 8FB20018 */  lw        $s2, 0x18($sp)
/* 42C908 802A9218 8FB10014 */  lw        $s1, 0x14($sp)
/* 42C90C 802A921C 8FB00010 */  lw        $s0, 0x10($sp)
/* 42C910 802A9220 03E00008 */  jr        $ra
/* 42C914 802A9224 27BD0028 */   addiu    $sp, $sp, 0x28
