.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel CopyBuffs
/* 19FA40 80271160 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19FA44 80271164 AFB10014 */  sw        $s1, 0x14($sp)
/* 19FA48 80271168 0080882D */  daddu     $s1, $a0, $zero
/* 19FA4C 8027116C AFBF001C */  sw        $ra, 0x1c($sp)
/* 19FA50 80271170 AFB20018 */  sw        $s2, 0x18($sp)
/* 19FA54 80271174 AFB00010 */  sw        $s0, 0x10($sp)
/* 19FA58 80271178 8E30000C */  lw        $s0, 0xc($s1)
/* 19FA5C 8027117C 8E050000 */  lw        $a1, ($s0)
/* 19FA60 80271180 0C0B1EAF */  jal       get_variable
/* 19FA64 80271184 26100004 */   addiu    $s0, $s0, 4
/* 19FA68 80271188 2412FF81 */  addiu     $s2, $zero, -0x7f
/* 19FA6C 8027118C 14520002 */  bne       $v0, $s2, .L80271198
/* 19FA70 80271190 00000000 */   nop
/* 19FA74 80271194 8E220148 */  lw        $v0, 0x148($s1)
.L80271198:
/* 19FA78 80271198 0C09A75B */  jal       get_actor
/* 19FA7C 8027119C 0040202D */   daddu    $a0, $v0, $zero
/* 19FA80 802711A0 0220202D */  daddu     $a0, $s1, $zero
/* 19FA84 802711A4 8E050000 */  lw        $a1, ($s0)
/* 19FA88 802711A8 0C0B1EAF */  jal       get_variable
/* 19FA8C 802711AC 0040802D */   daddu    $s0, $v0, $zero
/* 19FA90 802711B0 14520002 */  bne       $v0, $s2, .L802711BC
/* 19FA94 802711B4 00000000 */   nop
/* 19FA98 802711B8 8E220148 */  lw        $v0, 0x148($s1)
.L802711BC:
/* 19FA9C 802711BC 0C09A75B */  jal       get_actor
/* 19FAA0 802711C0 0040202D */   daddu    $a0, $v0, $zero
/* 19FAA4 802711C4 92040220 */  lbu       $a0, 0x220($s0)
/* 19FAA8 802711C8 0040182D */  daddu     $v1, $v0, $zero
/* 19FAAC 802711CC A0640220 */  sb        $a0, 0x220($v1)
/* 19FAB0 802711D0 92020221 */  lbu       $v0, 0x221($s0)
/* 19FAB4 802711D4 A0620221 */  sb        $v0, 0x221($v1)
/* 19FAB8 802711D8 92020222 */  lbu       $v0, 0x222($s0)
/* 19FABC 802711DC A0620222 */  sb        $v0, 0x222($v1)
/* 19FAC0 802711E0 92020223 */  lbu       $v0, 0x223($s0)
/* 19FAC4 802711E4 A0620223 */  sb        $v0, 0x223($v1)
/* 19FAC8 802711E8 92040224 */  lbu       $a0, 0x224($s0)
/* 19FACC 802711EC A0640224 */  sb        $a0, 0x224($v1)
/* 19FAD0 802711F0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19FAD4 802711F4 8FB20018 */  lw        $s2, 0x18($sp)
/* 19FAD8 802711F8 8FB10014 */  lw        $s1, 0x14($sp)
/* 19FADC 802711FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 19FAE0 80271200 24020002 */  addiu     $v0, $zero, 2
/* 19FAE4 80271204 03E00008 */  jr        $ra
/* 19FAE8 80271208 27BD0020 */   addiu    $sp, $sp, 0x20
/* 19FAEC 8027120C 00000000 */  nop
