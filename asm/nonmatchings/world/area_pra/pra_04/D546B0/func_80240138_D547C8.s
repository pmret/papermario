.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240138_D547C8
/* D547C8 80240138 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D547CC 8024013C AFB10014 */  sw        $s1, 0x14($sp)
/* D547D0 80240140 0080882D */  daddu     $s1, $a0, $zero
/* D547D4 80240144 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* D547D8 80240148 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* D547DC 8024014C AFBF0018 */  sw        $ra, 0x18($sp)
/* D547E0 80240150 AFB00010 */  sw        $s0, 0x10($sp)
/* D547E4 80240154 84430018 */  lh        $v1, 0x18($v0)
/* D547E8 80240158 14600005 */  bnez      $v1, .L80240170
/* D547EC 8024015C 0040802D */   daddu    $s0, $v0, $zero
/* D547F0 80240160 3C05FD05 */  lui       $a1, 0xfd05
/* D547F4 80240164 34A50F80 */  ori       $a1, $a1, 0xf80
/* D547F8 80240168 0C0B2026 */  jal       set_variable
/* D547FC 8024016C 0000302D */   daddu    $a2, $zero, $zero
.L80240170:
/* D54800 80240170 86030018 */  lh        $v1, 0x18($s0)
/* D54804 80240174 2402FF38 */  addiu     $v0, $zero, -0xc8
/* D54808 80240178 14620005 */  bne       $v1, $v0, .L80240190
/* D5480C 8024017C 0220202D */   daddu    $a0, $s1, $zero
/* D54810 80240180 3C05FD05 */  lui       $a1, 0xfd05
/* D54814 80240184 34A50F80 */  ori       $a1, $a1, 0xf80
/* D54818 80240188 0C0B2026 */  jal       set_variable
/* D5481C 8024018C 24060001 */   addiu    $a2, $zero, 1
.L80240190:
/* D54820 80240190 8FBF0018 */  lw        $ra, 0x18($sp)
/* D54824 80240194 8FB10014 */  lw        $s1, 0x14($sp)
/* D54828 80240198 8FB00010 */  lw        $s0, 0x10($sp)
/* D5482C 8024019C 0000102D */  daddu     $v0, $zero, $zero
/* D54830 802401A0 03E00008 */  jr        $ra
/* D54834 802401A4 27BD0020 */   addiu    $sp, $sp, 0x20
/* D54838 802401A8 00000000 */  nop       
/* D5483C 802401AC 00000000 */  nop       
