.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_DAD400
/* DAD400 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DAD404 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* DAD408 80240008 3C108024 */  lui       $s0, %hi(D_80242630_DAFA30)
/* DAD40C 8024000C 26102630 */  addiu     $s0, $s0, %lo(D_80242630_DAFA30)
/* DAD410 80240010 AFBF0018 */  sw        $ra, 0x18($sp)
/* DAD414 80240014 AFB10014 */  sw        $s1, 0x14($sp)
/* DAD418 80240018 8E020000 */  lw        $v0, ($s0)
/* DAD41C 8024001C 14400010 */  bnez      $v0, .L80240060
/* DAD420 80240020 0080882D */   daddu    $s1, $a0, $zero
/* DAD424 80240024 0C00AB39 */  jal       heap_malloc
/* DAD428 80240028 24040040 */   addiu    $a0, $zero, 0x40
/* DAD42C 8024002C AE020000 */  sw        $v0, ($s0)
/* DAD430 80240030 0000182D */  daddu     $v1, $zero, $zero
/* DAD434 80240034 0040282D */  daddu     $a1, $v0, $zero
/* DAD438 80240038 0220202D */  daddu     $a0, $s1, $zero
.L8024003C:
/* DAD43C 8024003C 8C820084 */  lw        $v0, 0x84($a0)
/* DAD440 80240040 24840004 */  addiu     $a0, $a0, 4
/* DAD444 80240044 24630001 */  addiu     $v1, $v1, 1
/* DAD448 80240048 ACA20000 */  sw        $v0, ($a1)
/* DAD44C 8024004C 28620010 */  slti      $v0, $v1, 0x10
/* DAD450 80240050 1440FFFA */  bnez      $v0, .L8024003C
/* DAD454 80240054 24A50004 */   addiu    $a1, $a1, 4
/* DAD458 80240058 08090027 */  j         .L8024009C
/* DAD45C 8024005C 00000000 */   nop
.L80240060:
/* DAD460 80240060 0000182D */  daddu     $v1, $zero, $zero
/* DAD464 80240064 0040282D */  daddu     $a1, $v0, $zero
/* DAD468 80240068 0220202D */  daddu     $a0, $s1, $zero
.L8024006C:
/* DAD46C 8024006C 8CA20000 */  lw        $v0, ($a1)
/* DAD470 80240070 24A50004 */  addiu     $a1, $a1, 4
/* DAD474 80240074 24630001 */  addiu     $v1, $v1, 1
/* DAD478 80240078 AC820084 */  sw        $v0, 0x84($a0)
/* DAD47C 8024007C 28620010 */  slti      $v0, $v1, 0x10
/* DAD480 80240080 1440FFFA */  bnez      $v0, .L8024006C
/* DAD484 80240084 24840004 */   addiu    $a0, $a0, 4
/* DAD488 80240088 3C108024 */  lui       $s0, %hi(D_80242630_DAFA30)
/* DAD48C 8024008C 26102630 */  addiu     $s0, $s0, %lo(D_80242630_DAFA30)
/* DAD490 80240090 0C00AB4B */  jal       heap_free
/* DAD494 80240094 8E040000 */   lw       $a0, ($s0)
/* DAD498 80240098 AE000000 */  sw        $zero, ($s0)
.L8024009C:
/* DAD49C 8024009C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DAD4A0 802400A0 8FB10014 */  lw        $s1, 0x14($sp)
/* DAD4A4 802400A4 8FB00010 */  lw        $s0, 0x10($sp)
/* DAD4A8 802400A8 24020002 */  addiu     $v0, $zero, 2
/* DAD4AC 802400AC 03E00008 */  jr        $ra
/* DAD4B0 802400B0 27BD0020 */   addiu    $sp, $sp, 0x20
