.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802421CC_DB448C
/* DB448C 802421CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DB4490 802421D0 AFBF0010 */  sw        $ra, 0x10($sp)
/* DB4494 802421D4 8C82000C */  lw        $v0, 0xc($a0)
/* DB4498 802421D8 0C0B1EAF */  jal       get_variable
/* DB449C 802421DC 8C450000 */   lw       $a1, ($v0)
/* DB44A0 802421E0 3C018024 */  lui       $at, 0x8024
/* DB44A4 802421E4 AC22309C */  sw        $v0, 0x309c($at)
/* DB44A8 802421E8 24020002 */  addiu     $v0, $zero, 2
/* DB44AC 802421EC 8FBF0010 */  lw        $ra, 0x10($sp)
/* DB44B0 802421F0 24030001 */  addiu     $v1, $zero, 1
/* DB44B4 802421F4 3C018024 */  lui       $at, 0x8024
/* DB44B8 802421F8 AC233098 */  sw        $v1, 0x3098($at)
/* DB44BC 802421FC 03E00008 */  jr        $ra
/* DB44C0 80242200 27BD0018 */   addiu    $sp, $sp, 0x18
