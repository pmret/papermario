.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241014_B9E974
/* B9E974 80241014 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B9E978 80241018 AFB00010 */  sw        $s0, 0x10($sp)
/* B9E97C 8024101C 3C108024 */  lui       $s0, 0x8024
/* B9E980 80241020 26102614 */  addiu     $s0, $s0, 0x2614
/* B9E984 80241024 AFBF0018 */  sw        $ra, 0x18($sp)
/* B9E988 80241028 AFB10014 */  sw        $s1, 0x14($sp)
/* B9E98C 8024102C 8E020000 */  lw        $v0, ($s0)
/* B9E990 80241030 14400010 */  bnez      $v0, .L80241074
/* B9E994 80241034 0080882D */   daddu    $s1, $a0, $zero
/* B9E998 80241038 0C00AB39 */  jal       heap_malloc
/* B9E99C 8024103C 24040040 */   addiu    $a0, $zero, 0x40
/* B9E9A0 80241040 AE020000 */  sw        $v0, ($s0)
/* B9E9A4 80241044 0000182D */  daddu     $v1, $zero, $zero
/* B9E9A8 80241048 0040282D */  daddu     $a1, $v0, $zero
/* B9E9AC 8024104C 0220202D */  daddu     $a0, $s1, $zero
.L80241050:
/* B9E9B0 80241050 8C820084 */  lw        $v0, 0x84($a0)
/* B9E9B4 80241054 24840004 */  addiu     $a0, $a0, 4
/* B9E9B8 80241058 24630001 */  addiu     $v1, $v1, 1
/* B9E9BC 8024105C ACA20000 */  sw        $v0, ($a1)
/* B9E9C0 80241060 28620010 */  slti      $v0, $v1, 0x10
/* B9E9C4 80241064 1440FFFA */  bnez      $v0, .L80241050
/* B9E9C8 80241068 24A50004 */   addiu    $a1, $a1, 4
/* B9E9CC 8024106C 0809042C */  j         .L802410B0
/* B9E9D0 80241070 00000000 */   nop      
.L80241074:
/* B9E9D4 80241074 0000182D */  daddu     $v1, $zero, $zero
/* B9E9D8 80241078 0040282D */  daddu     $a1, $v0, $zero
/* B9E9DC 8024107C 0220202D */  daddu     $a0, $s1, $zero
.L80241080:
/* B9E9E0 80241080 8CA20000 */  lw        $v0, ($a1)
/* B9E9E4 80241084 24A50004 */  addiu     $a1, $a1, 4
/* B9E9E8 80241088 24630001 */  addiu     $v1, $v1, 1
/* B9E9EC 8024108C AC820084 */  sw        $v0, 0x84($a0)
/* B9E9F0 80241090 28620010 */  slti      $v0, $v1, 0x10
/* B9E9F4 80241094 1440FFFA */  bnez      $v0, .L80241080
/* B9E9F8 80241098 24840004 */   addiu    $a0, $a0, 4
/* B9E9FC 8024109C 3C108024 */  lui       $s0, 0x8024
/* B9EA00 802410A0 26102614 */  addiu     $s0, $s0, 0x2614
/* B9EA04 802410A4 0C00AB4B */  jal       heap_free
/* B9EA08 802410A8 8E040000 */   lw       $a0, ($s0)
/* B9EA0C 802410AC AE000000 */  sw        $zero, ($s0)
.L802410B0:
/* B9EA10 802410B0 8FBF0018 */  lw        $ra, 0x18($sp)
/* B9EA14 802410B4 8FB10014 */  lw        $s1, 0x14($sp)
/* B9EA18 802410B8 8FB00010 */  lw        $s0, 0x10($sp)
/* B9EA1C 802410BC 24020002 */  addiu     $v0, $zero, 2
/* B9EA20 802410C0 03E00008 */  jr        $ra
/* B9EA24 802410C4 27BD0020 */   addiu    $sp, $sp, 0x20
