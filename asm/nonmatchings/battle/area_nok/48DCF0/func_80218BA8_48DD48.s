.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218BA8_48DD48
/* 48DD48 80218BA8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 48DD4C 80218BAC AFB10014 */  sw        $s1, 0x14($sp)
/* 48DD50 80218BB0 0080882D */  daddu     $s1, $a0, $zero
/* 48DD54 80218BB4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 48DD58 80218BB8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 48DD5C 80218BBC AFB20018 */  sw        $s2, 0x18($sp)
/* 48DD60 80218BC0 AFB00010 */  sw        $s0, 0x10($sp)
/* 48DD64 80218BC4 8E30000C */  lw        $s0, 0xc($s1)
/* 48DD68 80218BC8 8E050000 */  lw        $a1, ($s0)
/* 48DD6C 80218BCC 0C0B1EAF */  jal       get_variable
/* 48DD70 80218BD0 26100004 */   addiu    $s0, $s0, 4
/* 48DD74 80218BD4 8E050000 */  lw        $a1, ($s0)
/* 48DD78 80218BD8 26100004 */  addiu     $s0, $s0, 4
/* 48DD7C 80218BDC 0220202D */  daddu     $a0, $s1, $zero
/* 48DD80 80218BE0 0C0B1EAF */  jal       get_variable
/* 48DD84 80218BE4 0040982D */   daddu    $s3, $v0, $zero
/* 48DD88 80218BE8 8E050000 */  lw        $a1, ($s0)
/* 48DD8C 80218BEC 26100004 */  addiu     $s0, $s0, 4
/* 48DD90 80218BF0 0220202D */  daddu     $a0, $s1, $zero
/* 48DD94 80218BF4 0C0B1EAF */  jal       get_variable
/* 48DD98 80218BF8 0040902D */   daddu    $s2, $v0, $zero
/* 48DD9C 80218BFC 0220202D */  daddu     $a0, $s1, $zero
/* 48DDA0 80218C00 8E050000 */  lw        $a1, ($s0)
/* 48DDA4 80218C04 0C0B1EAF */  jal       get_variable
/* 48DDA8 80218C08 0040802D */   daddu    $s0, $v0, $zero
/* 48DDAC 80218C0C 8E240148 */  lw        $a0, 0x148($s1)
/* 48DDB0 80218C10 0C09A75B */  jal       get_actor
/* 48DDB4 80218C14 0040882D */   daddu    $s1, $v0, $zero
/* 48DDB8 80218C18 0040182D */  daddu     $v1, $v0, $zero
/* 48DDBC 80218C1C 8C620008 */  lw        $v0, 8($v1)
/* 48DDC0 80218C20 90420024 */  lbu       $v0, 0x24($v0)
/* 48DDC4 80218C24 8C640008 */  lw        $a0, 8($v1)
/* 48DDC8 80218C28 02629823 */  subu      $s3, $s3, $v0
/* 48DDCC 80218C2C A0730194 */  sb        $s3, 0x194($v1)
/* 48DDD0 80218C30 90820025 */  lbu       $v0, 0x25($a0)
/* 48DDD4 80218C34 02429023 */  subu      $s2, $s2, $v0
/* 48DDD8 80218C38 A0720195 */  sb        $s2, 0x195($v1)
/* 48DDDC 80218C3C 90820026 */  lbu       $v0, 0x26($a0)
/* 48DDE0 80218C40 02028023 */  subu      $s0, $s0, $v0
/* 48DDE4 80218C44 A0700196 */  sb        $s0, 0x196($v1)
/* 48DDE8 80218C48 90840027 */  lbu       $a0, 0x27($a0)
/* 48DDEC 80218C4C 02248823 */  subu      $s1, $s1, $a0
/* 48DDF0 80218C50 A0710197 */  sb        $s1, 0x197($v1)
/* 48DDF4 80218C54 8FBF0020 */  lw        $ra, 0x20($sp)
/* 48DDF8 80218C58 8FB3001C */  lw        $s3, 0x1c($sp)
/* 48DDFC 80218C5C 8FB20018 */  lw        $s2, 0x18($sp)
/* 48DE00 80218C60 8FB10014 */  lw        $s1, 0x14($sp)
/* 48DE04 80218C64 8FB00010 */  lw        $s0, 0x10($sp)
/* 48DE08 80218C68 24020002 */  addiu     $v0, $zero, 2
/* 48DE0C 80218C6C 03E00008 */  jr        $ra
/* 48DE10 80218C70 27BD0028 */   addiu    $sp, $sp, 0x28
