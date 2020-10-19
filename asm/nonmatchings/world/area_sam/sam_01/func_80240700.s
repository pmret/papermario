.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240700
/* CF8270 80240700 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CF8274 80240704 AFB00010 */  sw        $s0, 0x10($sp)
/* CF8278 80240708 3C108024 */  lui       $s0, 0x8024
/* CF827C 8024070C 261035F0 */  addiu     $s0, $s0, 0x35f0
/* CF8280 80240710 AFBF0018 */  sw        $ra, 0x18($sp)
/* CF8284 80240714 AFB10014 */  sw        $s1, 0x14($sp)
/* CF8288 80240718 8E020000 */  lw        $v0, ($s0)
/* CF828C 8024071C 14400010 */  bnez      $v0, .L80240760
/* CF8290 80240720 0080882D */   daddu    $s1, $a0, $zero
/* CF8294 80240724 0C00AB39 */  jal       heap_malloc
/* CF8298 80240728 24040040 */   addiu    $a0, $zero, 0x40
/* CF829C 8024072C AE020000 */  sw        $v0, ($s0)
/* CF82A0 80240730 0000182D */  daddu     $v1, $zero, $zero
/* CF82A4 80240734 0040282D */  daddu     $a1, $v0, $zero
/* CF82A8 80240738 0220202D */  daddu     $a0, $s1, $zero
.L8024073C:
/* CF82AC 8024073C 8C820084 */  lw        $v0, 0x84($a0)
/* CF82B0 80240740 24840004 */  addiu     $a0, $a0, 4
/* CF82B4 80240744 24630001 */  addiu     $v1, $v1, 1
/* CF82B8 80240748 ACA20000 */  sw        $v0, ($a1)
/* CF82BC 8024074C 28620010 */  slti      $v0, $v1, 0x10
/* CF82C0 80240750 1440FFFA */  bnez      $v0, .L8024073C
/* CF82C4 80240754 24A50004 */   addiu    $a1, $a1, 4
/* CF82C8 80240758 080901E7 */  j         .L8024079C
/* CF82CC 8024075C 00000000 */   nop      
.L80240760:
/* CF82D0 80240760 0000182D */  daddu     $v1, $zero, $zero
/* CF82D4 80240764 0040282D */  daddu     $a1, $v0, $zero
/* CF82D8 80240768 0220202D */  daddu     $a0, $s1, $zero
.L8024076C:
/* CF82DC 8024076C 8CA20000 */  lw        $v0, ($a1)
/* CF82E0 80240770 24A50004 */  addiu     $a1, $a1, 4
/* CF82E4 80240774 24630001 */  addiu     $v1, $v1, 1
/* CF82E8 80240778 AC820084 */  sw        $v0, 0x84($a0)
/* CF82EC 8024077C 28620010 */  slti      $v0, $v1, 0x10
/* CF82F0 80240780 1440FFFA */  bnez      $v0, .L8024076C
/* CF82F4 80240784 24840004 */   addiu    $a0, $a0, 4
/* CF82F8 80240788 3C108024 */  lui       $s0, 0x8024
/* CF82FC 8024078C 261035F0 */  addiu     $s0, $s0, 0x35f0
/* CF8300 80240790 0C00AB4B */  jal       heap_free
/* CF8304 80240794 8E040000 */   lw       $a0, ($s0)
/* CF8308 80240798 AE000000 */  sw        $zero, ($s0)
.L8024079C:
/* CF830C 8024079C 8FBF0018 */  lw        $ra, 0x18($sp)
/* CF8310 802407A0 8FB10014 */  lw        $s1, 0x14($sp)
/* CF8314 802407A4 8FB00010 */  lw        $s0, 0x10($sp)
/* CF8318 802407A8 24020002 */  addiu     $v0, $zero, 2
/* CF831C 802407AC 03E00008 */  jr        $ra
/* CF8320 802407B0 27BD0020 */   addiu    $sp, $sp, 0x20
