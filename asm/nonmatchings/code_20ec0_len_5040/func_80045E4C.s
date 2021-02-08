.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045E4C
/* 2124C 80045E4C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 21250 80045E50 AFBF0024 */  sw        $ra, 0x24($sp)
/* 21254 80045E54 AFB20020 */  sw        $s2, 0x20($sp)
/* 21258 80045E58 AFB1001C */  sw        $s1, 0x1c($sp)
/* 2125C 80045E5C AFB00018 */  sw        $s0, 0x18($sp)
/* 21260 80045E60 84820012 */  lh        $v0, 0x12($a0)
/* 21264 80045E64 24D00006 */  addiu     $s0, $a2, 6
/* 21268 80045E68 00021080 */  sll       $v0, $v0, 2
/* 2126C 80045E6C 3C128008 */  lui       $s2, %hi(D_80078168)
/* 21270 80045E70 02429021 */  addu      $s2, $s2, $v0
/* 21274 80045E74 8E528168 */  lw        $s2, %lo(D_80078168)($s2)
/* 21278 80045E78 24B1000F */  addiu     $s1, $a1, 0xf
/* 2127C 80045E7C 0C04992C */  jal       get_msg_lines
/* 21280 80045E80 0240202D */   daddu    $a0, $s2, $zero
/* 21284 80045E84 0240202D */  daddu     $a0, $s2, $zero
/* 21288 80045E88 2442FFFF */  addiu     $v0, $v0, -1
/* 2128C 80045E8C 00021040 */  sll       $v0, $v0, 1
/* 21290 80045E90 3C068008 */  lui       $a2, %hi(D_80078164)
/* 21294 80045E94 00C23021 */  addu      $a2, $a2, $v0
/* 21298 80045E98 84C68164 */  lh        $a2, %lo(D_80078164)($a2)
/* 2129C 80045E9C 2402000F */  addiu     $v0, $zero, 0xf
/* 212A0 80045EA0 0220282D */  daddu     $a1, $s1, $zero
/* 212A4 80045EA4 240700FF */  addiu     $a3, $zero, 0xff
/* 212A8 80045EA8 AFA20010 */  sw        $v0, 0x10($sp)
/* 212AC 80045EAC AFA00014 */  sw        $zero, 0x14($sp)
/* 212B0 80045EB0 0C04993B */  jal       draw_string
/* 212B4 80045EB4 02063021 */   addu     $a2, $s0, $a2
/* 212B8 80045EB8 8FBF0024 */  lw        $ra, 0x24($sp)
/* 212BC 80045EBC 8FB20020 */  lw        $s2, 0x20($sp)
/* 212C0 80045EC0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 212C4 80045EC4 8FB00018 */  lw        $s0, 0x18($sp)
/* 212C8 80045EC8 03E00008 */  jr        $ra
/* 212CC 80045ECC 27BD0028 */   addiu    $sp, $sp, 0x28
