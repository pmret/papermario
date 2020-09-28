.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80281434
/* 7E22B4 80281434 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7E22B8 80281438 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7E22BC 8028143C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7E22C0 80281440 AFBF0024 */  sw        $ra, 0x24($sp)
/* 7E22C4 80281444 AFB20020 */  sw        $s2, 0x20($sp)
/* 7E22C8 80281448 AFB1001C */  sw        $s1, 0x1c($sp)
/* 7E22CC 8028144C AFB00018 */  sw        $s0, 0x18($sp)
/* 7E22D0 80281450 8C440144 */  lw        $a0, 0x144($v0)
/* 7E22D4 80281454 00A0882D */  daddu     $s1, $a1, $zero
/* 7E22D8 80281458 8C830008 */  lw        $v1, 8($a0)
/* 7E22DC 8028145C 00C0902D */  daddu     $s2, $a2, $zero
/* 7E22E0 80281460 00031040 */  sll       $v0, $v1, 1
/* 7E22E4 80281464 00431021 */  addu      $v0, $v0, $v1
/* 7E22E8 80281468 8C830018 */  lw        $v1, 0x18($a0)
/* 7E22EC 8028146C 00021080 */  sll       $v0, $v0, 2
/* 7E22F0 80281470 00621821 */  addu      $v1, $v1, $v0
/* 7E22F4 80281474 8C700000 */  lw        $s0, ($v1)
/* 7E22F8 80281478 3C028008 */  lui       $v0, %hi(gItemTable)
/* 7E22FC 8028147C 244278E0 */  addiu     $v0, $v0, %lo(gItemTable)
/* 7E2300 80281480 00108140 */  sll       $s0, $s0, 5
/* 7E2304 80281484 02028021 */  addu      $s0, $s0, $v0
/* 7E2308 80281488 8E040000 */  lw        $a0, ($s0)
/* 7E230C 8028148C 0C04991D */  jal       get_string_width
/* 7E2310 80281490 0000282D */   daddu    $a1, $zero, $zero
/* 7E2314 80281494 00021043 */  sra       $v0, $v0, 1
/* 7E2318 80281498 2442FFC4 */  addiu     $v0, $v0, -0x3c
/* 7E231C 8028149C 02222823 */  subu      $a1, $s1, $v0
/* 7E2320 802814A0 26460006 */  addiu     $a2, $s2, 6
/* 7E2324 802814A4 AFA00010 */  sw        $zero, 0x10($sp)
/* 7E2328 802814A8 AFA00014 */  sw        $zero, 0x14($sp)
/* 7E232C 802814AC 8E040000 */  lw        $a0, ($s0)
/* 7E2330 802814B0 0C04993B */  jal       draw_string
/* 7E2334 802814B4 240700FF */   addiu    $a3, $zero, 0xff
/* 7E2338 802814B8 8FBF0024 */  lw        $ra, 0x24($sp)
/* 7E233C 802814BC 8FB20020 */  lw        $s2, 0x20($sp)
/* 7E2340 802814C0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7E2344 802814C4 8FB00018 */  lw        $s0, 0x18($sp)
/* 7E2348 802814C8 03E00008 */  jr        $ra
/* 7E234C 802814CC 27BD0028 */   addiu    $sp, $sp, 0x28
