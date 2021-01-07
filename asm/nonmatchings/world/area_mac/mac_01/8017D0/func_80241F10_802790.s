.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F10_802790
/* 802790 80241F10 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 802794 80241F14 AFB00010 */  sw        $s0, 0x10($sp)
/* 802798 80241F18 3C108025 */  lui       $s0, %hi(D_80248C30)
/* 80279C 80241F1C 26108C30 */  addiu     $s0, $s0, %lo(D_80248C30)
/* 8027A0 80241F20 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8027A4 80241F24 AFB10014 */  sw        $s1, 0x14($sp)
/* 8027A8 80241F28 8E020000 */  lw        $v0, ($s0)
/* 8027AC 80241F2C 14400010 */  bnez      $v0, .L80241F70
/* 8027B0 80241F30 0080882D */   daddu    $s1, $a0, $zero
/* 8027B4 80241F34 0C00AB39 */  jal       heap_malloc
/* 8027B8 80241F38 24040040 */   addiu    $a0, $zero, 0x40
/* 8027BC 80241F3C AE020000 */  sw        $v0, ($s0)
/* 8027C0 80241F40 0000182D */  daddu     $v1, $zero, $zero
/* 8027C4 80241F44 0040282D */  daddu     $a1, $v0, $zero
/* 8027C8 80241F48 0220202D */  daddu     $a0, $s1, $zero
.L80241F4C:
/* 8027CC 80241F4C 8C820084 */  lw        $v0, 0x84($a0)
/* 8027D0 80241F50 24840004 */  addiu     $a0, $a0, 4
/* 8027D4 80241F54 24630001 */  addiu     $v1, $v1, 1
/* 8027D8 80241F58 ACA20000 */  sw        $v0, ($a1)
/* 8027DC 80241F5C 28620010 */  slti      $v0, $v1, 0x10
/* 8027E0 80241F60 1440FFFA */  bnez      $v0, .L80241F4C
/* 8027E4 80241F64 24A50004 */   addiu    $a1, $a1, 4
/* 8027E8 80241F68 080907EB */  j         .L80241FAC
/* 8027EC 80241F6C 00000000 */   nop      
.L80241F70:
/* 8027F0 80241F70 0000182D */  daddu     $v1, $zero, $zero
/* 8027F4 80241F74 0040282D */  daddu     $a1, $v0, $zero
/* 8027F8 80241F78 0220202D */  daddu     $a0, $s1, $zero
.L80241F7C:
/* 8027FC 80241F7C 8CA20000 */  lw        $v0, ($a1)
/* 802800 80241F80 24A50004 */  addiu     $a1, $a1, 4
/* 802804 80241F84 24630001 */  addiu     $v1, $v1, 1
/* 802808 80241F88 AC820084 */  sw        $v0, 0x84($a0)
/* 80280C 80241F8C 28620010 */  slti      $v0, $v1, 0x10
/* 802810 80241F90 1440FFFA */  bnez      $v0, .L80241F7C
/* 802814 80241F94 24840004 */   addiu    $a0, $a0, 4
/* 802818 80241F98 3C108025 */  lui       $s0, %hi(D_80248C30)
/* 80281C 80241F9C 26108C30 */  addiu     $s0, $s0, %lo(D_80248C30)
/* 802820 80241FA0 0C00AB4B */  jal       heap_free
/* 802824 80241FA4 8E040000 */   lw       $a0, ($s0)
/* 802828 80241FA8 AE000000 */  sw        $zero, ($s0)
.L80241FAC:
/* 80282C 80241FAC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 802830 80241FB0 8FB10014 */  lw        $s1, 0x14($sp)
/* 802834 80241FB4 8FB00010 */  lw        $s0, 0x10($sp)
/* 802838 80241FB8 24020002 */  addiu     $v0, $zero, 2
/* 80283C 80241FBC 03E00008 */  jr        $ra
/* 802840 80241FC0 27BD0020 */   addiu    $sp, $sp, 0x20
