.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_item_entity_position
/* CA90C 8013420C 3C028015 */  lui       $v0, %hi(D_801565A0)
/* CA910 80134210 8C4265A0 */  lw        $v0, %lo(D_801565A0)($v0)
/* CA914 80134214 00042080 */  sll       $a0, $a0, 2
/* CA918 80134218 00822021 */  addu      $a0, $a0, $v0
/* CA91C 8013421C 8C820000 */  lw        $v0, ($a0)
/* CA920 80134220 AC450008 */  sw        $a1, 8($v0)
/* CA924 80134224 AC46000C */  sw        $a2, 0xc($v0)
/* CA928 80134228 03E00008 */  jr        $ra
/* CA92C 8013422C AC470010 */   sw       $a3, 0x10($v0)
