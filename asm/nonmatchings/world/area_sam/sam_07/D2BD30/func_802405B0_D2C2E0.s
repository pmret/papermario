.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405B0_D2C2E0
/* D2C2E0 802405B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D2C2E4 802405B4 AFB10014 */  sw        $s1, 0x14($sp)
/* D2C2E8 802405B8 0080882D */  daddu     $s1, $a0, $zero
/* D2C2EC 802405BC AFBF0018 */  sw        $ra, 0x18($sp)
/* D2C2F0 802405C0 AFB00010 */  sw        $s0, 0x10($sp)
/* D2C2F4 802405C4 8E30000C */  lw        $s0, 0xc($s1)
/* D2C2F8 802405C8 8E050000 */  lw        $a1, ($s0)
/* D2C2FC 802405CC 0C0B1EAF */  jal       get_variable
/* D2C300 802405D0 26100004 */   addiu    $s0, $s0, 4
/* D2C304 802405D4 0220202D */  daddu     $a0, $s1, $zero
/* D2C308 802405D8 8E050000 */  lw        $a1, ($s0)
/* D2C30C 802405DC 0C0B1EAF */  jal       get_variable
/* D2C310 802405E0 0040802D */   daddu    $s0, $v0, $zero
/* D2C314 802405E4 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x2)
/* D2C318 802405E8 8463A552 */  lh        $v1, %lo(gCollisionStatus+0x2)($v1)
/* D2C31C 802405EC 10700003 */  beq       $v1, $s0, .L802405FC
/* D2C320 802405F0 00000000 */   nop      
/* D2C324 802405F4 1462000A */  bne       $v1, $v0, .L80240620
/* D2C328 802405F8 24020002 */   addiu    $v0, $zero, 2
.L802405FC:
/* D2C32C 802405FC 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* D2C330 80240600 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* D2C334 80240604 804300B4 */  lb        $v1, 0xb4($v0)
/* D2C338 80240608 2402000E */  addiu     $v0, $zero, 0xe
/* D2C33C 8024060C 10620003 */  beq       $v1, $v0, .L8024061C
/* D2C340 80240610 24020010 */   addiu    $v0, $zero, 0x10
/* D2C344 80240614 14620002 */  bne       $v1, $v0, .L80240620
/* D2C348 80240618 24020002 */   addiu    $v0, $zero, 2
.L8024061C:
/* D2C34C 8024061C 0000102D */  daddu     $v0, $zero, $zero
.L80240620:
/* D2C350 80240620 8FBF0018 */  lw        $ra, 0x18($sp)
/* D2C354 80240624 8FB10014 */  lw        $s1, 0x14($sp)
/* D2C358 80240628 8FB00010 */  lw        $s0, 0x10($sp)
/* D2C35C 8024062C 03E00008 */  jr        $ra
/* D2C360 80240630 27BD0020 */   addiu    $sp, $sp, 0x20
