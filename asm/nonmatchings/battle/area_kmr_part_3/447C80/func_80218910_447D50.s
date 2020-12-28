.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218910_447D50
/* 447D50 80218910 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 447D54 80218914 AFB10014 */  sw        $s1, 0x14($sp)
/* 447D58 80218918 0080882D */  daddu     $s1, $a0, $zero
/* 447D5C 8021891C AFBF0020 */  sw        $ra, 0x20($sp)
/* 447D60 80218920 AFB3001C */  sw        $s3, 0x1c($sp)
/* 447D64 80218924 AFB20018 */  sw        $s2, 0x18($sp)
/* 447D68 80218928 AFB00010 */  sw        $s0, 0x10($sp)
/* 447D6C 8021892C 8E30000C */  lw        $s0, 0xc($s1)
/* 447D70 80218930 8E050000 */  lw        $a1, ($s0)
/* 447D74 80218934 0C0B1EAF */  jal       get_variable
/* 447D78 80218938 26100004 */   addiu    $s0, $s0, 4
/* 447D7C 8021893C 8E050000 */  lw        $a1, ($s0)
/* 447D80 80218940 26100004 */  addiu     $s0, $s0, 4
/* 447D84 80218944 0220202D */  daddu     $a0, $s1, $zero
/* 447D88 80218948 0C0B1EAF */  jal       get_variable
/* 447D8C 8021894C 0040982D */   daddu    $s3, $v0, $zero
/* 447D90 80218950 8E050000 */  lw        $a1, ($s0)
/* 447D94 80218954 26100004 */  addiu     $s0, $s0, 4
/* 447D98 80218958 0220202D */  daddu     $a0, $s1, $zero
/* 447D9C 8021895C 0C0B1EAF */  jal       get_variable
/* 447DA0 80218960 0040902D */   daddu    $s2, $v0, $zero
/* 447DA4 80218964 0220202D */  daddu     $a0, $s1, $zero
/* 447DA8 80218968 8E050000 */  lw        $a1, ($s0)
/* 447DAC 8021896C 0C0B1EAF */  jal       get_variable
/* 447DB0 80218970 0040802D */   daddu    $s0, $v0, $zero
/* 447DB4 80218974 8E240148 */  lw        $a0, 0x148($s1)
/* 447DB8 80218978 0C09A75B */  jal       get_actor
/* 447DBC 8021897C 0040882D */   daddu    $s1, $v0, $zero
/* 447DC0 80218980 0040182D */  daddu     $v1, $v0, $zero
/* 447DC4 80218984 8C620008 */  lw        $v0, 8($v1)
/* 447DC8 80218988 90420024 */  lbu       $v0, 0x24($v0)
/* 447DCC 8021898C 8C640008 */  lw        $a0, 8($v1)
/* 447DD0 80218990 02629823 */  subu      $s3, $s3, $v0
/* 447DD4 80218994 A0730194 */  sb        $s3, 0x194($v1)
/* 447DD8 80218998 90820025 */  lbu       $v0, 0x25($a0)
/* 447DDC 8021899C 02429023 */  subu      $s2, $s2, $v0
/* 447DE0 802189A0 A0720195 */  sb        $s2, 0x195($v1)
/* 447DE4 802189A4 90820026 */  lbu       $v0, 0x26($a0)
/* 447DE8 802189A8 02028023 */  subu      $s0, $s0, $v0
/* 447DEC 802189AC A0700196 */  sb        $s0, 0x196($v1)
/* 447DF0 802189B0 90840027 */  lbu       $a0, 0x27($a0)
/* 447DF4 802189B4 02248823 */  subu      $s1, $s1, $a0
/* 447DF8 802189B8 A0710197 */  sb        $s1, 0x197($v1)
/* 447DFC 802189BC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 447E00 802189C0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 447E04 802189C4 8FB20018 */  lw        $s2, 0x18($sp)
/* 447E08 802189C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 447E0C 802189CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 447E10 802189D0 24020002 */  addiu     $v0, $zero, 2
/* 447E14 802189D4 03E00008 */  jr        $ra
/* 447E18 802189D8 27BD0028 */   addiu    $sp, $sp, 0x28
