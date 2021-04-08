.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240068_EC9D68
/* EC9D68 80240068 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EC9D6C 8024006C AFB00010 */  sw        $s0, 0x10($sp)
/* EC9D70 80240070 0080802D */  daddu     $s0, $a0, $zero
/* EC9D74 80240074 AFBF0018 */  sw        $ra, 0x18($sp)
/* EC9D78 80240078 AFB10014 */  sw        $s1, 0x14($sp)
/* EC9D7C 8024007C 8E11000C */  lw        $s1, 0xc($s0)
/* EC9D80 80240080 8E250000 */  lw        $a1, ($s1)
/* EC9D84 80240084 0C0B53A3 */  jal       dead_get_variable
/* EC9D88 80240088 26310004 */   addiu    $s1, $s1, 4
/* EC9D8C 8024008C 0200202D */  daddu     $a0, $s0, $zero
/* EC9D90 80240090 3C038011 */  lui       $v1, %hi(D_80117840)
/* EC9D94 80240094 24637840 */  addiu     $v1, $v1, %lo(D_80117840)
/* EC9D98 80240098 000210C0 */  sll       $v0, $v0, 3
/* EC9D9C 8024009C 00431021 */  addu      $v0, $v0, $v1
/* EC9DA0 802400A0 90460015 */  lbu       $a2, 0x15($v0)
/* EC9DA4 802400A4 8E250000 */  lw        $a1, ($s1)
/* EC9DA8 802400A8 24C60001 */  addiu     $a2, $a2, 1
/* EC9DAC 802400AC A0460015 */  sb        $a2, 0x15($v0)
/* EC9DB0 802400B0 00063600 */  sll       $a2, $a2, 0x18
/* EC9DB4 802400B4 0C0B551A */  jal       dead_set_variable
/* EC9DB8 802400B8 00063603 */   sra      $a2, $a2, 0x18
/* EC9DBC 802400BC 8FBF0018 */  lw        $ra, 0x18($sp)
/* EC9DC0 802400C0 8FB10014 */  lw        $s1, 0x14($sp)
/* EC9DC4 802400C4 8FB00010 */  lw        $s0, 0x10($sp)
/* EC9DC8 802400C8 24020002 */  addiu     $v0, $zero, 2
/* EC9DCC 802400CC 03E00008 */  jr        $ra
/* EC9DD0 802400D0 27BD0020 */   addiu    $sp, $sp, 0x20
