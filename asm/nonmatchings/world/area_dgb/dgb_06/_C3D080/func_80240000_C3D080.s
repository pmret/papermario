.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_C3D080
/* C3D080 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C3D084 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* C3D088 80240008 3C108024 */  lui       $s0, 0x8024
/* C3D08C 8024000C 26100620 */  addiu     $s0, $s0, 0x620
/* C3D090 80240010 AFBF0018 */  sw        $ra, 0x18($sp)
/* C3D094 80240014 AFB10014 */  sw        $s1, 0x14($sp)
/* C3D098 80240018 8E020000 */  lw        $v0, ($s0)
/* C3D09C 8024001C 14400010 */  bnez      $v0, .L80240060
/* C3D0A0 80240020 0080882D */   daddu    $s1, $a0, $zero
/* C3D0A4 80240024 0C00AB39 */  jal       heap_malloc
/* C3D0A8 80240028 24040040 */   addiu    $a0, $zero, 0x40
/* C3D0AC 8024002C AE020000 */  sw        $v0, ($s0)
/* C3D0B0 80240030 0000182D */  daddu     $v1, $zero, $zero
/* C3D0B4 80240034 0040282D */  daddu     $a1, $v0, $zero
/* C3D0B8 80240038 0220202D */  daddu     $a0, $s1, $zero
.L8024003C:
/* C3D0BC 8024003C 8C820084 */  lw        $v0, 0x84($a0)
/* C3D0C0 80240040 24840004 */  addiu     $a0, $a0, 4
/* C3D0C4 80240044 24630001 */  addiu     $v1, $v1, 1
/* C3D0C8 80240048 ACA20000 */  sw        $v0, ($a1)
/* C3D0CC 8024004C 28620010 */  slti      $v0, $v1, 0x10
/* C3D0D0 80240050 1440FFFA */  bnez      $v0, .L8024003C
/* C3D0D4 80240054 24A50004 */   addiu    $a1, $a1, 4
/* C3D0D8 80240058 08090027 */  j         .L8024009C
/* C3D0DC 8024005C 00000000 */   nop      
.L80240060:
/* C3D0E0 80240060 0000182D */  daddu     $v1, $zero, $zero
/* C3D0E4 80240064 0040282D */  daddu     $a1, $v0, $zero
/* C3D0E8 80240068 0220202D */  daddu     $a0, $s1, $zero
.L8024006C:
/* C3D0EC 8024006C 8CA20000 */  lw        $v0, ($a1)
/* C3D0F0 80240070 24A50004 */  addiu     $a1, $a1, 4
/* C3D0F4 80240074 24630001 */  addiu     $v1, $v1, 1
/* C3D0F8 80240078 AC820084 */  sw        $v0, 0x84($a0)
/* C3D0FC 8024007C 28620010 */  slti      $v0, $v1, 0x10
/* C3D100 80240080 1440FFFA */  bnez      $v0, .L8024006C
/* C3D104 80240084 24840004 */   addiu    $a0, $a0, 4
/* C3D108 80240088 3C108024 */  lui       $s0, 0x8024
/* C3D10C 8024008C 26100620 */  addiu     $s0, $s0, 0x620
/* C3D110 80240090 0C00AB4B */  jal       heap_free
/* C3D114 80240094 8E040000 */   lw       $a0, ($s0)
/* C3D118 80240098 AE000000 */  sw        $zero, ($s0)
.L8024009C:
/* C3D11C 8024009C 8FBF0018 */  lw        $ra, 0x18($sp)
/* C3D120 802400A0 8FB10014 */  lw        $s1, 0x14($sp)
/* C3D124 802400A4 8FB00010 */  lw        $s0, 0x10($sp)
/* C3D128 802400A8 24020002 */  addiu     $v0, $zero, 2
/* C3D12C 802400AC 03E00008 */  jr        $ra
/* C3D130 802400B0 27BD0020 */   addiu    $sp, $sp, 0x20
