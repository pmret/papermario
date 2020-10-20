.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240380_A57830
/* A57830 80240380 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A57834 80240384 AFB00010 */  sw        $s0, 0x10($sp)
/* A57838 80240388 3C108024 */  lui       $s0, 0x8024
/* A5783C 8024038C 26101900 */  addiu     $s0, $s0, 0x1900
/* A57840 80240390 AFBF0018 */  sw        $ra, 0x18($sp)
/* A57844 80240394 AFB10014 */  sw        $s1, 0x14($sp)
/* A57848 80240398 8E020000 */  lw        $v0, ($s0)
/* A5784C 8024039C 14400010 */  bnez      $v0, .L802403E0
/* A57850 802403A0 0080882D */   daddu    $s1, $a0, $zero
/* A57854 802403A4 0C00AB39 */  jal       heap_malloc
/* A57858 802403A8 24040040 */   addiu    $a0, $zero, 0x40
/* A5785C 802403AC AE020000 */  sw        $v0, ($s0)
/* A57860 802403B0 0000182D */  daddu     $v1, $zero, $zero
/* A57864 802403B4 0040282D */  daddu     $a1, $v0, $zero
/* A57868 802403B8 0220202D */  daddu     $a0, $s1, $zero
.L802403BC:
/* A5786C 802403BC 8C820084 */  lw        $v0, 0x84($a0)
/* A57870 802403C0 24840004 */  addiu     $a0, $a0, 4
/* A57874 802403C4 24630001 */  addiu     $v1, $v1, 1
/* A57878 802403C8 ACA20000 */  sw        $v0, ($a1)
/* A5787C 802403CC 28620010 */  slti      $v0, $v1, 0x10
/* A57880 802403D0 1440FFFA */  bnez      $v0, .L802403BC
/* A57884 802403D4 24A50004 */   addiu    $a1, $a1, 4
/* A57888 802403D8 08090107 */  j         .L8024041C
/* A5788C 802403DC 00000000 */   nop      
.L802403E0:
/* A57890 802403E0 0000182D */  daddu     $v1, $zero, $zero
/* A57894 802403E4 0040282D */  daddu     $a1, $v0, $zero
/* A57898 802403E8 0220202D */  daddu     $a0, $s1, $zero
.L802403EC:
/* A5789C 802403EC 8CA20000 */  lw        $v0, ($a1)
/* A578A0 802403F0 24A50004 */  addiu     $a1, $a1, 4
/* A578A4 802403F4 24630001 */  addiu     $v1, $v1, 1
/* A578A8 802403F8 AC820084 */  sw        $v0, 0x84($a0)
/* A578AC 802403FC 28620010 */  slti      $v0, $v1, 0x10
/* A578B0 80240400 1440FFFA */  bnez      $v0, .L802403EC
/* A578B4 80240404 24840004 */   addiu    $a0, $a0, 4
/* A578B8 80240408 3C108024 */  lui       $s0, 0x8024
/* A578BC 8024040C 26101900 */  addiu     $s0, $s0, 0x1900
/* A578C0 80240410 0C00AB4B */  jal       heap_free
/* A578C4 80240414 8E040000 */   lw       $a0, ($s0)
/* A578C8 80240418 AE000000 */  sw        $zero, ($s0)
.L8024041C:
/* A578CC 8024041C 8FBF0018 */  lw        $ra, 0x18($sp)
/* A578D0 80240420 8FB10014 */  lw        $s1, 0x14($sp)
/* A578D4 80240424 8FB00010 */  lw        $s0, 0x10($sp)
/* A578D8 80240428 24020002 */  addiu     $v0, $zero, 2
/* A578DC 8024042C 03E00008 */  jr        $ra
/* A578E0 80240430 27BD0020 */   addiu    $sp, $sp, 0x20
