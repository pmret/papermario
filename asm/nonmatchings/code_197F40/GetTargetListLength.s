.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetTargetListLength
/* 19D144 8026E864 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19D148 8026E868 AFB00010 */  sw        $s0, 0x10($sp)
/* 19D14C 8026E86C 0080802D */  daddu     $s0, $a0, $zero
/* 19D150 8026E870 AFBF0018 */  sw        $ra, 0x18($sp)
/* 19D154 8026E874 AFB10014 */  sw        $s1, 0x14($sp)
/* 19D158 8026E878 8E040148 */  lw        $a0, 0x148($s0)
/* 19D15C 8026E87C 0C09A75B */  jal       get_actor
/* 19D160 8026E880 8E11000C */   lw       $s1, 0xc($s0)
/* 19D164 8026E884 8E250000 */  lw        $a1, ($s1)
/* 19D168 8026E888 8046040C */  lb        $a2, 0x40c($v0)
/* 19D16C 8026E88C 0C0B2026 */  jal       set_variable
/* 19D170 8026E890 0200202D */   daddu    $a0, $s0, $zero
/* 19D174 8026E894 8FBF0018 */  lw        $ra, 0x18($sp)
/* 19D178 8026E898 8FB10014 */  lw        $s1, 0x14($sp)
/* 19D17C 8026E89C 8FB00010 */  lw        $s0, 0x10($sp)
/* 19D180 8026E8A0 24020002 */  addiu     $v0, $zero, 2
/* 19D184 8026E8A4 03E00008 */  jr        $ra
/* 19D188 8026E8A8 27BD0020 */   addiu    $sp, $sp, 0x20
