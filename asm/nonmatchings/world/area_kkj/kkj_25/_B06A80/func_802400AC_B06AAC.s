.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400AC_B06AAC
/* B06AAC 802400AC 8C8400C0 */  lw        $a0, 0xc0($a0)
/* B06AB0 802400B0 8C83000C */  lw        $v1, 0xc($a0)
/* B06AB4 802400B4 24020055 */  addiu     $v0, $zero, 0x55
/* B06AB8 802400B8 AC620030 */  sw        $v0, 0x30($v1)
/* B06ABC 802400BC 8C83000C */  lw        $v1, 0xc($a0)
/* B06AC0 802400C0 2402002A */  addiu     $v0, $zero, 0x2a
/* B06AC4 802400C4 AC620034 */  sw        $v0, 0x34($v1)
/* B06AC8 802400C8 8C82000C */  lw        $v0, 0xc($a0)
/* B06ACC 802400CC 240300FF */  addiu     $v1, $zero, 0xff
/* B06AD0 802400D0 AC430038 */  sw        $v1, 0x38($v0)
/* B06AD4 802400D4 8C82000C */  lw        $v0, 0xc($a0)
/* B06AD8 802400D8 AC430040 */  sw        $v1, 0x40($v0)
/* B06ADC 802400DC 8C83000C */  lw        $v1, 0xc($a0)
/* B06AE0 802400E0 240200AF */  addiu     $v0, $zero, 0xaf
/* B06AE4 802400E4 AC620044 */  sw        $v0, 0x44($v1)
/* B06AE8 802400E8 8C83000C */  lw        $v1, 0xc($a0)
/* B06AEC 802400EC 240200EF */  addiu     $v0, $zero, 0xef
/* B06AF0 802400F0 AC620048 */  sw        $v0, 0x48($v1)
/* B06AF4 802400F4 03E00008 */  jr        $ra
/* B06AF8 802400F8 24020002 */   addiu    $v0, $zero, 2
