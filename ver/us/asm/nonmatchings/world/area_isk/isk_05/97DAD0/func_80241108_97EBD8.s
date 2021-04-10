.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241108_97EBD8
/* 97EBD8 80241108 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 97EBDC 8024110C AFB40030 */  sw        $s4, 0x30($sp)
/* 97EBE0 80241110 27B40010 */  addiu     $s4, $sp, 0x10
/* 97EBE4 80241114 AFB3002C */  sw        $s3, 0x2c($sp)
/* 97EBE8 80241118 0000982D */  daddu     $s3, $zero, $zero
/* 97EBEC 8024111C AFBF0038 */  sw        $ra, 0x38($sp)
/* 97EBF0 80241120 AFB50034 */  sw        $s5, 0x34($sp)
/* 97EBF4 80241124 AFB20028 */  sw        $s2, 0x28($sp)
/* 97EBF8 80241128 AFB10024 */  sw        $s1, 0x24($sp)
/* 97EBFC 8024112C AFB00020 */  sw        $s0, 0x20($sp)
/* 97EC00 80241130 8C84014C */  lw        $a0, 0x14c($a0)
/* 97EC04 80241134 0C00EAD2 */  jal       get_npc_safe
/* 97EC08 80241138 24150003 */   addiu    $s5, $zero, 3
/* 97EC0C 8024113C 24040080 */  addiu     $a0, $zero, 0x80
/* 97EC10 80241140 0C00AB39 */  jal       heap_malloc
/* 97EC14 80241144 0040882D */   daddu    $s1, $v0, $zero
/* 97EC18 80241148 0040902D */  daddu     $s2, $v0, $zero
/* 97EC1C 8024114C 3C030035 */  lui       $v1, 0x35
/* 97EC20 80241150 34630002 */  ori       $v1, $v1, 2
/* 97EC24 80241154 2650000C */  addiu     $s0, $s2, 0xc
/* 97EC28 80241158 3402814A */  ori       $v0, $zero, 0x814a
/* 97EC2C 8024115C AE320020 */  sw        $s2, 0x20($s1)
/* 97EC30 80241160 AFA20010 */  sw        $v0, 0x10($sp)
/* 97EC34 80241164 AFA30014 */  sw        $v1, 0x14($sp)
/* 97EC38 80241168 AFA00018 */  sw        $zero, 0x18($sp)
/* 97EC3C 8024116C AFA0001C */  sw        $zero, 0x1c($sp)
.L80241170:
/* 97EC40 80241170 0C00E211 */  jal       npc_create_basic
/* 97EC44 80241174 0280202D */   daddu    $a0, $s4, $zero
/* 97EC48 80241178 0C00E2B7 */  jal       get_npc_by_index
/* 97EC4C 8024117C 0040202D */   daddu    $a0, $v0, $zero
/* 97EC50 80241180 AE420000 */  sw        $v0, ($s2)
/* 97EC54 80241184 C6200038 */  lwc1      $f0, 0x38($s1)
/* 97EC58 80241188 E4400038 */  swc1      $f0, 0x38($v0)
/* 97EC5C 8024118C C620003C */  lwc1      $f0, 0x3c($s1)
/* 97EC60 80241190 0040202D */  daddu     $a0, $v0, $zero
/* 97EC64 80241194 E480003C */  swc1      $f0, 0x3c($a0)
/* 97EC68 80241198 C6200040 */  lwc1      $f0, 0x40($s1)
/* 97EC6C 8024119C 26730001 */  addiu     $s3, $s3, 1
/* 97EC70 802411A0 E4800040 */  swc1      $f0, 0x40($a0)
/* 97EC74 802411A4 C620000C */  lwc1      $f0, 0xc($s1)
/* 97EC78 802411A8 26520010 */  addiu     $s2, $s2, 0x10
/* 97EC7C 802411AC A09500AB */  sb        $s5, 0xab($a0)
/* 97EC80 802411B0 0C00EAFF */  jal       disable_npc_shadow
/* 97EC84 802411B4 E480000C */   swc1     $f0, 0xc($a0)
/* 97EC88 802411B8 AE00FFF8 */  sw        $zero, -8($s0)
/* 97EC8C 802411BC AE00FFFC */  sw        $zero, -4($s0)
/* 97EC90 802411C0 AE000000 */  sw        $zero, ($s0)
/* 97EC94 802411C4 2A620008 */  slti      $v0, $s3, 8
/* 97EC98 802411C8 1440FFE9 */  bnez      $v0, .L80241170
/* 97EC9C 802411CC 26100010 */   addiu    $s0, $s0, 0x10
/* 97ECA0 802411D0 8FBF0038 */  lw        $ra, 0x38($sp)
/* 97ECA4 802411D4 8FB50034 */  lw        $s5, 0x34($sp)
/* 97ECA8 802411D8 8FB40030 */  lw        $s4, 0x30($sp)
/* 97ECAC 802411DC 8FB3002C */  lw        $s3, 0x2c($sp)
/* 97ECB0 802411E0 8FB20028 */  lw        $s2, 0x28($sp)
/* 97ECB4 802411E4 8FB10024 */  lw        $s1, 0x24($sp)
/* 97ECB8 802411E8 8FB00020 */  lw        $s0, 0x20($sp)
/* 97ECBC 802411EC 24020002 */  addiu     $v0, $zero, 2
/* 97ECC0 802411F0 03E00008 */  jr        $ra
/* 97ECC4 802411F4 27BD0040 */   addiu    $sp, $sp, 0x40
