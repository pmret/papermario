.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243124_9AB514
/* 9AB514 80243124 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 9AB518 80243128 AFB40040 */  sw        $s4, 0x40($sp)
/* 9AB51C 8024312C 0080A02D */  daddu     $s4, $a0, $zero
/* 9AB520 80243130 AFBF0048 */  sw        $ra, 0x48($sp)
/* 9AB524 80243134 AFB50044 */  sw        $s5, 0x44($sp)
/* 9AB528 80243138 AFB3003C */  sw        $s3, 0x3c($sp)
/* 9AB52C 8024313C AFB20038 */  sw        $s2, 0x38($sp)
/* 9AB530 80243140 AFB10034 */  sw        $s1, 0x34($sp)
/* 9AB534 80243144 AFB00030 */  sw        $s0, 0x30($sp)
/* 9AB538 80243148 8E920148 */  lw        $s2, 0x148($s4)
/* 9AB53C 8024314C 86440008 */  lh        $a0, 8($s2)
/* 9AB540 80243150 8E90000C */  lw        $s0, 0xc($s4)
/* 9AB544 80243154 0C00EABB */  jal       get_npc_unsafe
/* 9AB548 80243158 00A0882D */   daddu    $s1, $a1, $zero
/* 9AB54C 8024315C 0280202D */  daddu     $a0, $s4, $zero
/* 9AB550 80243160 8E050000 */  lw        $a1, ($s0)
/* 9AB554 80243164 0C0B1EAF */  jal       get_variable
/* 9AB558 80243168 0040A82D */   daddu    $s5, $v0, $zero
/* 9AB55C 8024316C AFA00010 */  sw        $zero, 0x10($sp)
/* 9AB560 80243170 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9AB564 80243174 8C630030 */  lw        $v1, 0x30($v1)
/* 9AB568 80243178 AFA30014 */  sw        $v1, 0x14($sp)
/* 9AB56C 8024317C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9AB570 80243180 8C63001C */  lw        $v1, 0x1c($v1)
/* 9AB574 80243184 AFA30018 */  sw        $v1, 0x18($sp)
/* 9AB578 80243188 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9AB57C 8024318C 8C630024 */  lw        $v1, 0x24($v1)
/* 9AB580 80243190 AFA3001C */  sw        $v1, 0x1c($sp)
/* 9AB584 80243194 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9AB588 80243198 8C630028 */  lw        $v1, 0x28($v1)
/* 9AB58C 8024319C 27B30010 */  addiu     $s3, $sp, 0x10
/* 9AB590 802431A0 AFA30020 */  sw        $v1, 0x20($sp)
/* 9AB594 802431A4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9AB598 802431A8 3C0142F0 */  lui       $at, 0x42f0
/* 9AB59C 802431AC 44810000 */  mtc1      $at, $f0
/* 9AB5A0 802431B0 8C63002C */  lw        $v1, 0x2c($v1)
/* 9AB5A4 802431B4 0040802D */  daddu     $s0, $v0, $zero
/* 9AB5A8 802431B8 E7A00028 */  swc1      $f0, 0x28($sp)
/* 9AB5AC 802431BC A7A0002C */  sh        $zero, 0x2c($sp)
/* 9AB5B0 802431C0 12200006 */  beqz      $s1, .L802431DC
/* 9AB5B4 802431C4 AFA30024 */   sw       $v1, 0x24($sp)
/* 9AB5B8 802431C8 02A0202D */  daddu     $a0, $s5, $zero
/* 9AB5BC 802431CC 0240282D */  daddu     $a1, $s2, $zero
/* 9AB5C0 802431D0 0280302D */  daddu     $a2, $s4, $zero
/* 9AB5C4 802431D4 0C090C00 */  jal       trd_04_UnkFunc5
/* 9AB5C8 802431D8 0200382D */   daddu    $a3, $s0, $zero
.L802431DC:
/* 9AB5CC 802431DC 2402FFFE */  addiu     $v0, $zero, -2
/* 9AB5D0 802431E0 A2A200AB */  sb        $v0, 0xab($s5)
/* 9AB5D4 802431E4 8E4300B0 */  lw        $v1, 0xb0($s2)
/* 9AB5D8 802431E8 30620004 */  andi      $v0, $v1, 4
/* 9AB5DC 802431EC 10400007 */  beqz      $v0, .L8024320C
/* 9AB5E0 802431F0 00000000 */   nop
/* 9AB5E4 802431F4 824200B4 */  lb        $v0, 0xb4($s2)
/* 9AB5E8 802431F8 1440003C */  bnez      $v0, .L802432EC
/* 9AB5EC 802431FC 0000102D */   daddu    $v0, $zero, $zero
/* 9AB5F0 80243200 2402FFFB */  addiu     $v0, $zero, -5
/* 9AB5F4 80243204 00621024 */  and       $v0, $v1, $v0
/* 9AB5F8 80243208 AE4200B0 */  sw        $v0, 0xb0($s2)
.L8024320C:
/* 9AB5FC 8024320C 8E830070 */  lw        $v1, 0x70($s4)
/* 9AB600 80243210 2C62000F */  sltiu     $v0, $v1, 0xf
/* 9AB604 80243214 10400034 */  beqz      $v0, L802432E8_9AB6D8
/* 9AB608 80243218 00031080 */   sll      $v0, $v1, 2
/* 9AB60C 8024321C 3C018024 */  lui       $at, %hi(jtbl_80246288_9AE678)
/* 9AB610 80243220 00220821 */  addu      $at, $at, $v0
/* 9AB614 80243224 8C226288 */  lw        $v0, %lo(jtbl_80246288_9AE678)($at)
/* 9AB618 80243228 00400008 */  jr        $v0
/* 9AB61C 8024322C 00000000 */   nop
glabel L80243230_9AB620
/* 9AB620 80243230 0280202D */  daddu     $a0, $s4, $zero
/* 9AB624 80243234 0200282D */  daddu     $a1, $s0, $zero
/* 9AB628 80243238 0C090786 */  jal       func_80241E18_9AA208
/* 9AB62C 8024323C 0260302D */   daddu    $a2, $s3, $zero
glabel L80243240_9AB630
/* 9AB630 80243240 0280202D */  daddu     $a0, $s4, $zero
/* 9AB634 80243244 0200282D */  daddu     $a1, $s0, $zero
/* 9AB638 80243248 0C0907F2 */  jal       func_80241FC8_9AA3B8
/* 9AB63C 8024324C 0260302D */   daddu    $a2, $s3, $zero
/* 9AB640 80243250 08090CBB */  j         .L802432EC
/* 9AB644 80243254 0000102D */   daddu    $v0, $zero, $zero
glabel L80243258_9AB648
/* 9AB648 80243258 0280202D */  daddu     $a0, $s4, $zero
/* 9AB64C 8024325C 0200282D */  daddu     $a1, $s0, $zero
/* 9AB650 80243260 0C09097C */  jal       dup_trd_04_UnkNpcAIFunc1
/* 9AB654 80243264 0260302D */   daddu    $a2, $s3, $zero
glabel L80243268_9AB658
/* 9AB658 80243268 0280202D */  daddu     $a0, $s4, $zero
/* 9AB65C 8024326C 0200282D */  daddu     $a1, $s0, $zero
/* 9AB660 80243270 0C0909AC */  jal       trd_04_UnkFunc4
/* 9AB664 80243274 0260302D */   daddu    $a2, $s3, $zero
/* 9AB668 80243278 08090CBB */  j         .L802432EC
/* 9AB66C 8024327C 0000102D */   daddu    $v0, $zero, $zero
glabel L80243280_9AB670
/* 9AB670 80243280 0280202D */  daddu     $a0, $s4, $zero
/* 9AB674 80243284 0200282D */  daddu     $a1, $s0, $zero
/* 9AB678 80243288 0C090A7D */  jal       trd_04_UnkNpcAIFunc2
/* 9AB67C 8024328C 0260302D */   daddu    $a2, $s3, $zero
glabel L80243290_9AB680
/* 9AB680 80243290 0280202D */  daddu     $a0, $s4, $zero
/* 9AB684 80243294 0200282D */  daddu     $a1, $s0, $zero
/* 9AB688 80243298 0C090A9B */  jal       func_80242A6C_9AAE5C
/* 9AB68C 8024329C 0260302D */   daddu    $a2, $s3, $zero
/* 9AB690 802432A0 08090CBB */  j         .L802432EC
/* 9AB694 802432A4 0000102D */   daddu    $v0, $zero, $zero
glabel L802432A8_9AB698
/* 9AB698 802432A8 0280202D */  daddu     $a0, $s4, $zero
/* 9AB69C 802432AC 0200282D */  daddu     $a1, $s0, $zero
/* 9AB6A0 802432B0 0C090AB6 */  jal       trd_04_UnkNpcAIFunc14
/* 9AB6A4 802432B4 0260302D */   daddu    $a2, $s3, $zero
/* 9AB6A8 802432B8 08090CBB */  j         .L802432EC
/* 9AB6AC 802432BC 0000102D */   daddu    $v0, $zero, $zero
glabel L802432C0_9AB6B0
/* 9AB6B0 802432C0 0280202D */  daddu     $a0, $s4, $zero
/* 9AB6B4 802432C4 0200282D */  daddu     $a1, $s0, $zero
/* 9AB6B8 802432C8 0C090B03 */  jal       trd_04_UnkNpcAIFunc3
/* 9AB6BC 802432CC 0260302D */   daddu    $a2, $s3, $zero
/* 9AB6C0 802432D0 08090CBB */  j         .L802432EC
/* 9AB6C4 802432D4 0000102D */   daddu    $v0, $zero, $zero
glabel L802432D8_9AB6C8
/* 9AB6C8 802432D8 0280202D */  daddu     $a0, $s4, $zero
/* 9AB6CC 802432DC 0200282D */  daddu     $a1, $s0, $zero
/* 9AB6D0 802432E0 0C090B1C */  jal       trd_04_UnkFunc6
/* 9AB6D4 802432E4 0260302D */   daddu    $a2, $s3, $zero
glabel L802432E8_9AB6D8
/* 9AB6D8 802432E8 0000102D */  daddu     $v0, $zero, $zero
.L802432EC:
/* 9AB6DC 802432EC 8FBF0048 */  lw        $ra, 0x48($sp)
/* 9AB6E0 802432F0 8FB50044 */  lw        $s5, 0x44($sp)
/* 9AB6E4 802432F4 8FB40040 */  lw        $s4, 0x40($sp)
/* 9AB6E8 802432F8 8FB3003C */  lw        $s3, 0x3c($sp)
/* 9AB6EC 802432FC 8FB20038 */  lw        $s2, 0x38($sp)
/* 9AB6F0 80243300 8FB10034 */  lw        $s1, 0x34($sp)
/* 9AB6F4 80243304 8FB00030 */  lw        $s0, 0x30($sp)
/* 9AB6F8 80243308 03E00008 */  jr        $ra
/* 9AB6FC 8024330C 27BD0050 */   addiu    $sp, $sp, 0x50
