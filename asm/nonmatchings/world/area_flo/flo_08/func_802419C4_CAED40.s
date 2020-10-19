.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419C4_CB0704
/* CB0704 802419C4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CB0708 802419C8 AFBF0010 */  sw        $ra, 0x10($sp)
/* CB070C 802419CC 8C82000C */  lw        $v0, 0xc($a0)
/* CB0710 802419D0 0C0B1EAF */  jal       get_variable
/* CB0714 802419D4 8C450000 */   lw       $a1, ($v0)
/* CB0718 802419D8 3C018024 */  lui       $at, 0x8024
/* CB071C 802419DC AC22308C */  sw        $v0, 0x308c($at)
/* CB0720 802419E0 24020002 */  addiu     $v0, $zero, 2
/* CB0724 802419E4 8FBF0010 */  lw        $ra, 0x10($sp)
/* CB0728 802419E8 24030001 */  addiu     $v1, $zero, 1
/* CB072C 802419EC 3C018024 */  lui       $at, 0x8024
/* CB0730 802419F0 AC233088 */  sw        $v1, 0x3088($at)
/* CB0734 802419F4 03E00008 */  jr        $ra
/* CB0738 802419F8 27BD0018 */   addiu    $sp, $sp, 0x18
