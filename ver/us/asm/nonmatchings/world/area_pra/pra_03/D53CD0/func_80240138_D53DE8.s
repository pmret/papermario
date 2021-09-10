.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240138_D53DE8
/* D53DE8 80240138 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D53DEC 8024013C AFB10014 */  sw        $s1, 0x14($sp)
/* D53DF0 80240140 0080882D */  daddu     $s1, $a0, $zero
/* D53DF4 80240144 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* D53DF8 80240148 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* D53DFC 8024014C AFBF0018 */  sw        $ra, 0x18($sp)
/* D53E00 80240150 AFB00010 */  sw        $s0, 0x10($sp)
/* D53E04 80240154 84430018 */  lh        $v1, 0x18($v0)
/* D53E08 80240158 14600005 */  bnez      $v1, .L80240170
/* D53E0C 8024015C 0040802D */   daddu    $s0, $v0, $zero
/* D53E10 80240160 3C05FD05 */  lui       $a1, 0xfd05
/* D53E14 80240164 34A50F80 */  ori       $a1, $a1, 0xf80
/* D53E18 80240168 0C0B2026 */  jal       evt_set_variable
/* D53E1C 8024016C 0000302D */   daddu    $a2, $zero, $zero
.L80240170:
/* D53E20 80240170 86030018 */  lh        $v1, 0x18($s0)
/* D53E24 80240174 2402FF38 */  addiu     $v0, $zero, -0xc8
/* D53E28 80240178 14620005 */  bne       $v1, $v0, .L80240190
/* D53E2C 8024017C 0220202D */   daddu    $a0, $s1, $zero
/* D53E30 80240180 3C05FD05 */  lui       $a1, 0xfd05
/* D53E34 80240184 34A50F80 */  ori       $a1, $a1, 0xf80
/* D53E38 80240188 0C0B2026 */  jal       evt_set_variable
/* D53E3C 8024018C 24060001 */   addiu    $a2, $zero, 1
.L80240190:
/* D53E40 80240190 8FBF0018 */  lw        $ra, 0x18($sp)
/* D53E44 80240194 8FB10014 */  lw        $s1, 0x14($sp)
/* D53E48 80240198 8FB00010 */  lw        $s0, 0x10($sp)
/* D53E4C 8024019C 0000102D */  daddu     $v0, $zero, $zero
/* D53E50 802401A0 03E00008 */  jr        $ra
/* D53E54 802401A4 27BD0020 */   addiu    $sp, $sp, 0x20
/* D53E58 802401A8 00000000 */  nop
/* D53E5C 802401AC 00000000 */  nop
