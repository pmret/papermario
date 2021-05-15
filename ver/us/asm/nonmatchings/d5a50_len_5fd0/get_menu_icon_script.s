.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_menu_icon_script
/* DAFB0 801448B0 2402F7FF */  addiu     $v0, $zero, -0x801
/* DAFB4 801448B4 00822024 */  and       $a0, $a0, $v0
/* DAFB8 801448B8 3C028015 */  lui       $v0, %hi(gHudElementList)
/* DAFBC 801448BC 8C427960 */  lw        $v0, %lo(gHudElementList)($v0)
/* DAFC0 801448C0 00042080 */  sll       $a0, $a0, 2
/* DAFC4 801448C4 00822021 */  addu      $a0, $a0, $v0
/* DAFC8 801448C8 8C820000 */  lw        $v0, ($a0)
/* DAFCC 801448CC 03E00008 */  jr        $ra
/* DAFD0 801448D0 8C420008 */   lw       $v0, 8($v0)
