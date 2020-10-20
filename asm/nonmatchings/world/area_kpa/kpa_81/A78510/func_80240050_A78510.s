.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240050_A78510
/* A78510 80240050 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A78514 80240054 AFB10014 */  sw        $s1, 0x14($sp)
/* A78518 80240058 0080882D */  daddu     $s1, $a0, $zero
/* A7851C 8024005C AFBF0018 */  sw        $ra, 0x18($sp)
/* A78520 80240060 AFB00010 */  sw        $s0, 0x10($sp)
/* A78524 80240064 8E30000C */  lw        $s0, 0xc($s1)
/* A78528 80240068 8E050000 */  lw        $a1, ($s0)
/* A7852C 8024006C 0C0B1EAF */  jal       get_variable
/* A78530 80240070 26100004 */   addiu    $s0, $s0, 4
/* A78534 80240074 0C00EAD2 */  jal       get_npc_safe
/* A78538 80240078 0040202D */   daddu    $a0, $v0, $zero
/* A7853C 8024007C 10400005 */  beqz      $v0, .L80240094
/* A78540 80240080 00000000 */   nop      
/* A78544 80240084 8E050000 */  lw        $a1, ($s0)
/* A78548 80240088 844600A8 */  lh        $a2, 0xa8($v0)
/* A7854C 8024008C 0C0B2026 */  jal       set_variable
/* A78550 80240090 0220202D */   daddu    $a0, $s1, $zero
.L80240094:
/* A78554 80240094 8FBF0018 */  lw        $ra, 0x18($sp)
/* A78558 80240098 8FB10014 */  lw        $s1, 0x14($sp)
/* A7855C 8024009C 8FB00010 */  lw        $s0, 0x10($sp)
/* A78560 802400A0 24020002 */  addiu     $v0, $zero, 2
/* A78564 802400A4 03E00008 */  jr        $ra
/* A78568 802400A8 27BD0020 */   addiu    $sp, $sp, 0x20
