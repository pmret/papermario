.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B9C_B3676C
/* B3676C 80241B9C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B36770 80241BA0 AFB00010 */  sw        $s0, 0x10($sp)
/* B36774 80241BA4 3C108024 */  lui       $s0, 0x8024
/* B36778 80241BA8 26107764 */  addiu     $s0, $s0, 0x7764
/* B3677C 80241BAC AFBF0018 */  sw        $ra, 0x18($sp)
/* B36780 80241BB0 AFB10014 */  sw        $s1, 0x14($sp)
/* B36784 80241BB4 8E020000 */  lw        $v0, ($s0)
/* B36788 80241BB8 14400010 */  bnez      $v0, .L80241BFC
/* B3678C 80241BBC 0080882D */   daddu    $s1, $a0, $zero
/* B36790 80241BC0 0C00AB39 */  jal       heap_malloc
/* B36794 80241BC4 24040040 */   addiu    $a0, $zero, 0x40
/* B36798 80241BC8 AE020000 */  sw        $v0, ($s0)
/* B3679C 80241BCC 0000182D */  daddu     $v1, $zero, $zero
/* B367A0 80241BD0 0040282D */  daddu     $a1, $v0, $zero
/* B367A4 80241BD4 0220202D */  daddu     $a0, $s1, $zero
.L80241BD8:
/* B367A8 80241BD8 8C820084 */  lw        $v0, 0x84($a0)
/* B367AC 80241BDC 24840004 */  addiu     $a0, $a0, 4
/* B367B0 80241BE0 24630001 */  addiu     $v1, $v1, 1
/* B367B4 80241BE4 ACA20000 */  sw        $v0, ($a1)
/* B367B8 80241BE8 28620010 */  slti      $v0, $v1, 0x10
/* B367BC 80241BEC 1440FFFA */  bnez      $v0, .L80241BD8
/* B367C0 80241BF0 24A50004 */   addiu    $a1, $a1, 4
/* B367C4 80241BF4 0809070E */  j         .L80241C38
/* B367C8 80241BF8 00000000 */   nop      
.L80241BFC:
/* B367CC 80241BFC 0000182D */  daddu     $v1, $zero, $zero
/* B367D0 80241C00 0040282D */  daddu     $a1, $v0, $zero
/* B367D4 80241C04 0220202D */  daddu     $a0, $s1, $zero
.L80241C08:
/* B367D8 80241C08 8CA20000 */  lw        $v0, ($a1)
/* B367DC 80241C0C 24A50004 */  addiu     $a1, $a1, 4
/* B367E0 80241C10 24630001 */  addiu     $v1, $v1, 1
/* B367E4 80241C14 AC820084 */  sw        $v0, 0x84($a0)
/* B367E8 80241C18 28620010 */  slti      $v0, $v1, 0x10
/* B367EC 80241C1C 1440FFFA */  bnez      $v0, .L80241C08
/* B367F0 80241C20 24840004 */   addiu    $a0, $a0, 4
/* B367F4 80241C24 3C108024 */  lui       $s0, 0x8024
/* B367F8 80241C28 26107764 */  addiu     $s0, $s0, 0x7764
/* B367FC 80241C2C 0C00AB4B */  jal       heap_free
/* B36800 80241C30 8E040000 */   lw       $a0, ($s0)
/* B36804 80241C34 AE000000 */  sw        $zero, ($s0)
.L80241C38:
/* B36808 80241C38 8FBF0018 */  lw        $ra, 0x18($sp)
/* B3680C 80241C3C 8FB10014 */  lw        $s1, 0x14($sp)
/* B36810 80241C40 8FB00010 */  lw        $s0, 0x10($sp)
/* B36814 80241C44 24020002 */  addiu     $v0, $zero, 2
/* B36818 80241C48 03E00008 */  jr        $ra
/* B3681C 80241C4C 27BD0020 */   addiu    $sp, $sp, 0x20
