.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802424A4
/* A1D5A4 802424A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A1D5A8 802424A8 AFB00010 */  sw        $s0, 0x10($sp)
/* A1D5AC 802424AC 3C108025 */  lui       $s0, 0x8025
/* A1D5B0 802424B0 2610801C */  addiu     $s0, $s0, -0x7fe4
/* A1D5B4 802424B4 AFBF0018 */  sw        $ra, 0x18($sp)
/* A1D5B8 802424B8 AFB10014 */  sw        $s1, 0x14($sp)
/* A1D5BC 802424BC 8E020000 */  lw        $v0, ($s0)
/* A1D5C0 802424C0 14400010 */  bnez      $v0, .L80242504
/* A1D5C4 802424C4 0080882D */   daddu    $s1, $a0, $zero
/* A1D5C8 802424C8 0C00AB39 */  jal       heap_malloc
/* A1D5CC 802424CC 24040040 */   addiu    $a0, $zero, 0x40
/* A1D5D0 802424D0 AE020000 */  sw        $v0, ($s0)
/* A1D5D4 802424D4 0000182D */  daddu     $v1, $zero, $zero
/* A1D5D8 802424D8 0040282D */  daddu     $a1, $v0, $zero
/* A1D5DC 802424DC 0220202D */  daddu     $a0, $s1, $zero
.L802424E0:
/* A1D5E0 802424E0 8C820084 */  lw        $v0, 0x84($a0)
/* A1D5E4 802424E4 24840004 */  addiu     $a0, $a0, 4
/* A1D5E8 802424E8 24630001 */  addiu     $v1, $v1, 1
/* A1D5EC 802424EC ACA20000 */  sw        $v0, ($a1)
/* A1D5F0 802424F0 28620010 */  slti      $v0, $v1, 0x10
/* A1D5F4 802424F4 1440FFFA */  bnez      $v0, .L802424E0
/* A1D5F8 802424F8 24A50004 */   addiu    $a1, $a1, 4
/* A1D5FC 802424FC 08090950 */  j         .L80242540
/* A1D600 80242500 00000000 */   nop      
.L80242504:
/* A1D604 80242504 0000182D */  daddu     $v1, $zero, $zero
/* A1D608 80242508 0040282D */  daddu     $a1, $v0, $zero
/* A1D60C 8024250C 0220202D */  daddu     $a0, $s1, $zero
.L80242510:
/* A1D610 80242510 8CA20000 */  lw        $v0, ($a1)
/* A1D614 80242514 24A50004 */  addiu     $a1, $a1, 4
/* A1D618 80242518 24630001 */  addiu     $v1, $v1, 1
/* A1D61C 8024251C AC820084 */  sw        $v0, 0x84($a0)
/* A1D620 80242520 28620010 */  slti      $v0, $v1, 0x10
/* A1D624 80242524 1440FFFA */  bnez      $v0, .L80242510
/* A1D628 80242528 24840004 */   addiu    $a0, $a0, 4
/* A1D62C 8024252C 3C108025 */  lui       $s0, 0x8025
/* A1D630 80242530 2610801C */  addiu     $s0, $s0, -0x7fe4
/* A1D634 80242534 0C00AB4B */  jal       heap_free
/* A1D638 80242538 8E040000 */   lw       $a0, ($s0)
/* A1D63C 8024253C AE000000 */  sw        $zero, ($s0)
.L80242540:
/* A1D640 80242540 8FBF0018 */  lw        $ra, 0x18($sp)
/* A1D644 80242544 8FB10014 */  lw        $s1, 0x14($sp)
/* A1D648 80242548 8FB00010 */  lw        $s0, 0x10($sp)
/* A1D64C 8024254C 24020002 */  addiu     $v0, $zero, 2
/* A1D650 80242550 03E00008 */  jr        $ra
/* A1D654 80242554 27BD0020 */   addiu    $sp, $sp, 0x20
