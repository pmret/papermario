.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024027C_CC10AC
/* CC10AC 8024027C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CC10B0 80240280 AFB00010 */  sw        $s0, 0x10($sp)
/* CC10B4 80240284 3C108024 */  lui       $s0, 0x8024
/* CC10B8 80240288 261017EC */  addiu     $s0, $s0, 0x17ec
/* CC10BC 8024028C AFBF0018 */  sw        $ra, 0x18($sp)
/* CC10C0 80240290 AFB10014 */  sw        $s1, 0x14($sp)
/* CC10C4 80240294 8E020000 */  lw        $v0, ($s0)
/* CC10C8 80240298 14400010 */  bnez      $v0, .L802402DC
/* CC10CC 8024029C 0080882D */   daddu    $s1, $a0, $zero
/* CC10D0 802402A0 0C00AB39 */  jal       heap_malloc
/* CC10D4 802402A4 24040040 */   addiu    $a0, $zero, 0x40
/* CC10D8 802402A8 AE020000 */  sw        $v0, ($s0)
/* CC10DC 802402AC 0000182D */  daddu     $v1, $zero, $zero
/* CC10E0 802402B0 0040282D */  daddu     $a1, $v0, $zero
/* CC10E4 802402B4 0220202D */  daddu     $a0, $s1, $zero
.L802402B8:
/* CC10E8 802402B8 8C820084 */  lw        $v0, 0x84($a0)
/* CC10EC 802402BC 24840004 */  addiu     $a0, $a0, 4
/* CC10F0 802402C0 24630001 */  addiu     $v1, $v1, 1
/* CC10F4 802402C4 ACA20000 */  sw        $v0, ($a1)
/* CC10F8 802402C8 28620010 */  slti      $v0, $v1, 0x10
/* CC10FC 802402CC 1440FFFA */  bnez      $v0, .L802402B8
/* CC1100 802402D0 24A50004 */   addiu    $a1, $a1, 4
/* CC1104 802402D4 080900C6 */  j         .L80240318
/* CC1108 802402D8 00000000 */   nop      
.L802402DC:
/* CC110C 802402DC 0000182D */  daddu     $v1, $zero, $zero
/* CC1110 802402E0 0040282D */  daddu     $a1, $v0, $zero
/* CC1114 802402E4 0220202D */  daddu     $a0, $s1, $zero
.L802402E8:
/* CC1118 802402E8 8CA20000 */  lw        $v0, ($a1)
/* CC111C 802402EC 24A50004 */  addiu     $a1, $a1, 4
/* CC1120 802402F0 24630001 */  addiu     $v1, $v1, 1
/* CC1124 802402F4 AC820084 */  sw        $v0, 0x84($a0)
/* CC1128 802402F8 28620010 */  slti      $v0, $v1, 0x10
/* CC112C 802402FC 1440FFFA */  bnez      $v0, .L802402E8
/* CC1130 80240300 24840004 */   addiu    $a0, $a0, 4
/* CC1134 80240304 3C108024 */  lui       $s0, 0x8024
/* CC1138 80240308 261017EC */  addiu     $s0, $s0, 0x17ec
/* CC113C 8024030C 0C00AB4B */  jal       heap_free
/* CC1140 80240310 8E040000 */   lw       $a0, ($s0)
/* CC1144 80240314 AE000000 */  sw        $zero, ($s0)
.L80240318:
/* CC1148 80240318 8FBF0018 */  lw        $ra, 0x18($sp)
/* CC114C 8024031C 8FB10014 */  lw        $s1, 0x14($sp)
/* CC1150 80240320 8FB00010 */  lw        $s0, 0x10($sp)
/* CC1154 80240324 24020002 */  addiu     $v0, $zero, 2
/* CC1158 80240328 03E00008 */  jr        $ra
/* CC115C 8024032C 27BD0020 */   addiu    $sp, $sp, 0x20
