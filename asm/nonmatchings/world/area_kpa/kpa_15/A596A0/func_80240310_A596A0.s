.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_A596A0
/* A596A0 80240310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A596A4 80240314 AFB00010 */  sw        $s0, 0x10($sp)
/* A596A8 80240318 3C108024 */  lui       $s0, %hi(func_80240AA0_95BCA0)
/* A596AC 8024031C 26100AA0 */  addiu     $s0, $s0, %lo(func_80240AA0_95BCA0)
/* A596B0 80240320 AFBF0018 */  sw        $ra, 0x18($sp)
/* A596B4 80240324 AFB10014 */  sw        $s1, 0x14($sp)
/* A596B8 80240328 8E020000 */  lw        $v0, ($s0)
/* A596BC 8024032C 14400010 */  bnez      $v0, .L80240370
/* A596C0 80240330 0080882D */   daddu    $s1, $a0, $zero
/* A596C4 80240334 0C00AB39 */  jal       heap_malloc
/* A596C8 80240338 24040040 */   addiu    $a0, $zero, 0x40
/* A596CC 8024033C AE020000 */  sw        $v0, ($s0)
/* A596D0 80240340 0000182D */  daddu     $v1, $zero, $zero
/* A596D4 80240344 0040282D */  daddu     $a1, $v0, $zero
/* A596D8 80240348 0220202D */  daddu     $a0, $s1, $zero
.L8024034C:
/* A596DC 8024034C 8C820084 */  lw        $v0, 0x84($a0)
/* A596E0 80240350 24840004 */  addiu     $a0, $a0, 4
/* A596E4 80240354 24630001 */  addiu     $v1, $v1, 1
/* A596E8 80240358 ACA20000 */  sw        $v0, ($a1)
/* A596EC 8024035C 28620010 */  slti      $v0, $v1, 0x10
/* A596F0 80240360 1440FFFA */  bnez      $v0, .L8024034C
/* A596F4 80240364 24A50004 */   addiu    $a1, $a1, 4
/* A596F8 80240368 080900EB */  j         .L802403AC
/* A596FC 8024036C 00000000 */   nop      
.L80240370:
/* A59700 80240370 0000182D */  daddu     $v1, $zero, $zero
/* A59704 80240374 0040282D */  daddu     $a1, $v0, $zero
/* A59708 80240378 0220202D */  daddu     $a0, $s1, $zero
.L8024037C:
/* A5970C 8024037C 8CA20000 */  lw        $v0, ($a1)
/* A59710 80240380 24A50004 */  addiu     $a1, $a1, 4
/* A59714 80240384 24630001 */  addiu     $v1, $v1, 1
/* A59718 80240388 AC820084 */  sw        $v0, 0x84($a0)
/* A5971C 8024038C 28620010 */  slti      $v0, $v1, 0x10
/* A59720 80240390 1440FFFA */  bnez      $v0, .L8024037C
/* A59724 80240394 24840004 */   addiu    $a0, $a0, 4
/* A59728 80240398 3C108024 */  lui       $s0, %hi(func_80240AA0_95BCA0)
/* A5972C 8024039C 26100AA0 */  addiu     $s0, $s0, %lo(func_80240AA0_95BCA0)
/* A59730 802403A0 0C00AB4B */  jal       heap_free
/* A59734 802403A4 8E040000 */   lw       $a0, ($s0)
/* A59738 802403A8 AE000000 */  sw        $zero, ($s0)
.L802403AC:
/* A5973C 802403AC 8FBF0018 */  lw        $ra, 0x18($sp)
/* A59740 802403B0 8FB10014 */  lw        $s1, 0x14($sp)
/* A59744 802403B4 8FB00010 */  lw        $s0, 0x10($sp)
/* A59748 802403B8 24020002 */  addiu     $v0, $zero, 2
/* A5974C 802403BC 03E00008 */  jr        $ra
/* A59750 802403C0 27BD0020 */   addiu    $sp, $sp, 0x20
