.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel load_string
/* BC000 80125900 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BC004 80125904 AFBF0010 */  sw        $ra, 0x10($sp)
/* BC008 80125908 0C049647 */  jal       _load_string
/* BC00C 8012590C 0000302D */   daddu    $a2, $zero, $zero
/* BC010 80125910 8FBF0010 */  lw        $ra, 0x10($sp)
/* BC014 80125914 03E00008 */  jr        $ra
/* BC018 80125918 27BD0018 */   addiu    $sp, $sp, 0x18
