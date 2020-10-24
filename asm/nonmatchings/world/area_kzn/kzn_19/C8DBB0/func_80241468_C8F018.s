.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241468_C8F018
/* C8F018 80241468 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C8F01C 8024146C AFB00010 */  sw        $s0, 0x10($sp)
/* C8F020 80241470 3C108024 */  lui       $s0, 0x8024
/* C8F024 80241474 26103D74 */  addiu     $s0, $s0, 0x3d74
/* C8F028 80241478 AFBF0018 */  sw        $ra, 0x18($sp)
/* C8F02C 8024147C AFB10014 */  sw        $s1, 0x14($sp)
/* C8F030 80241480 8E020000 */  lw        $v0, ($s0)
/* C8F034 80241484 14400010 */  bnez      $v0, .L802414C8
/* C8F038 80241488 0080882D */   daddu    $s1, $a0, $zero
/* C8F03C 8024148C 0C00AB39 */  jal       heap_malloc
/* C8F040 80241490 24040040 */   addiu    $a0, $zero, 0x40
/* C8F044 80241494 AE020000 */  sw        $v0, ($s0)
/* C8F048 80241498 0000182D */  daddu     $v1, $zero, $zero
/* C8F04C 8024149C 0040282D */  daddu     $a1, $v0, $zero
/* C8F050 802414A0 0220202D */  daddu     $a0, $s1, $zero
.L802414A4:
/* C8F054 802414A4 8C820084 */  lw        $v0, 0x84($a0)
/* C8F058 802414A8 24840004 */  addiu     $a0, $a0, 4
/* C8F05C 802414AC 24630001 */  addiu     $v1, $v1, 1
/* C8F060 802414B0 ACA20000 */  sw        $v0, ($a1)
/* C8F064 802414B4 28620010 */  slti      $v0, $v1, 0x10
/* C8F068 802414B8 1440FFFA */  bnez      $v0, .L802414A4
/* C8F06C 802414BC 24A50004 */   addiu    $a1, $a1, 4
/* C8F070 802414C0 08090541 */  j         .L80241504
/* C8F074 802414C4 00000000 */   nop      
.L802414C8:
/* C8F078 802414C8 0000182D */  daddu     $v1, $zero, $zero
/* C8F07C 802414CC 0040282D */  daddu     $a1, $v0, $zero
/* C8F080 802414D0 0220202D */  daddu     $a0, $s1, $zero
.L802414D4:
/* C8F084 802414D4 8CA20000 */  lw        $v0, ($a1)
/* C8F088 802414D8 24A50004 */  addiu     $a1, $a1, 4
/* C8F08C 802414DC 24630001 */  addiu     $v1, $v1, 1
/* C8F090 802414E0 AC820084 */  sw        $v0, 0x84($a0)
/* C8F094 802414E4 28620010 */  slti      $v0, $v1, 0x10
/* C8F098 802414E8 1440FFFA */  bnez      $v0, .L802414D4
/* C8F09C 802414EC 24840004 */   addiu    $a0, $a0, 4
/* C8F0A0 802414F0 3C108024 */  lui       $s0, 0x8024
/* C8F0A4 802414F4 26103D74 */  addiu     $s0, $s0, 0x3d74
/* C8F0A8 802414F8 0C00AB4B */  jal       heap_free
/* C8F0AC 802414FC 8E040000 */   lw       $a0, ($s0)
/* C8F0B0 80241500 AE000000 */  sw        $zero, ($s0)
.L80241504:
/* C8F0B4 80241504 8FBF0018 */  lw        $ra, 0x18($sp)
/* C8F0B8 80241508 8FB10014 */  lw        $s1, 0x14($sp)
/* C8F0BC 8024150C 8FB00010 */  lw        $s0, 0x10($sp)
/* C8F0C0 80241510 24020002 */  addiu     $v0, $zero, 2
/* C8F0C4 80241514 03E00008 */  jr        $ra
/* C8F0C8 80241518 27BD0020 */   addiu    $sp, $sp, 0x20
