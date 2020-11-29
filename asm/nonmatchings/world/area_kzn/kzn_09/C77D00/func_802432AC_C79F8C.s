.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802432AC_C79F8C
/* C79F8C 802432AC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C79F90 802432B0 AFB00010 */  sw        $s0, 0x10($sp)
/* C79F94 802432B4 3C108024 */  lui       $s0, %hi(D_80245250)
/* C79F98 802432B8 26105250 */  addiu     $s0, $s0, %lo(D_80245250)
/* C79F9C 802432BC AFBF0018 */  sw        $ra, 0x18($sp)
/* C79FA0 802432C0 AFB10014 */  sw        $s1, 0x14($sp)
/* C79FA4 802432C4 8E020000 */  lw        $v0, ($s0)
/* C79FA8 802432C8 14400010 */  bnez      $v0, .L8024330C
/* C79FAC 802432CC 0080882D */   daddu    $s1, $a0, $zero
/* C79FB0 802432D0 0C00AB39 */  jal       heap_malloc
/* C79FB4 802432D4 24040040 */   addiu    $a0, $zero, 0x40
/* C79FB8 802432D8 AE020000 */  sw        $v0, ($s0)
/* C79FBC 802432DC 0000182D */  daddu     $v1, $zero, $zero
/* C79FC0 802432E0 0040282D */  daddu     $a1, $v0, $zero
/* C79FC4 802432E4 0220202D */  daddu     $a0, $s1, $zero
.L802432E8:
/* C79FC8 802432E8 8C820084 */  lw        $v0, 0x84($a0)
/* C79FCC 802432EC 24840004 */  addiu     $a0, $a0, 4
/* C79FD0 802432F0 24630001 */  addiu     $v1, $v1, 1
/* C79FD4 802432F4 ACA20000 */  sw        $v0, ($a1)
/* C79FD8 802432F8 28620010 */  slti      $v0, $v1, 0x10
/* C79FDC 802432FC 1440FFFA */  bnez      $v0, .L802432E8
/* C79FE0 80243300 24A50004 */   addiu    $a1, $a1, 4
/* C79FE4 80243304 08090CD2 */  j         .L80243348
/* C79FE8 80243308 00000000 */   nop      
.L8024330C:
/* C79FEC 8024330C 0000182D */  daddu     $v1, $zero, $zero
/* C79FF0 80243310 0040282D */  daddu     $a1, $v0, $zero
/* C79FF4 80243314 0220202D */  daddu     $a0, $s1, $zero
.L80243318:
/* C79FF8 80243318 8CA20000 */  lw        $v0, ($a1)
/* C79FFC 8024331C 24A50004 */  addiu     $a1, $a1, 4
/* C7A000 80243320 24630001 */  addiu     $v1, $v1, 1
/* C7A004 80243324 AC820084 */  sw        $v0, 0x84($a0)
/* C7A008 80243328 28620010 */  slti      $v0, $v1, 0x10
/* C7A00C 8024332C 1440FFFA */  bnez      $v0, .L80243318
/* C7A010 80243330 24840004 */   addiu    $a0, $a0, 4
/* C7A014 80243334 3C108024 */  lui       $s0, %hi(D_80245250)
/* C7A018 80243338 26105250 */  addiu     $s0, $s0, %lo(D_80245250)
/* C7A01C 8024333C 0C00AB4B */  jal       heap_free
/* C7A020 80243340 8E040000 */   lw       $a0, ($s0)
/* C7A024 80243344 AE000000 */  sw        $zero, ($s0)
.L80243348:
/* C7A028 80243348 8FBF0018 */  lw        $ra, 0x18($sp)
/* C7A02C 8024334C 8FB10014 */  lw        $s1, 0x14($sp)
/* C7A030 80243350 8FB00010 */  lw        $s0, 0x10($sp)
/* C7A034 80243354 24020002 */  addiu     $v0, $zero, 2
/* C7A038 80243358 03E00008 */  jr        $ra
/* C7A03C 8024335C 27BD0020 */   addiu    $sp, $sp, 0x20
