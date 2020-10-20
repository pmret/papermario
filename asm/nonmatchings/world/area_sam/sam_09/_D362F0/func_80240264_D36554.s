.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240264_D36554
/* D36554 80240264 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D36558 80240268 AFB10014 */  sw        $s1, 0x14($sp)
/* D3655C 8024026C 0080882D */  daddu     $s1, $a0, $zero
/* D36560 80240270 3C05F5DE */  lui       $a1, 0xf5de
/* D36564 80240274 34A50288 */  ori       $a1, $a1, 0x288
/* D36568 80240278 AFBF0018 */  sw        $ra, 0x18($sp)
/* D3656C 8024027C 0C0B1EAF */  jal       get_variable
/* D36570 80240280 AFB00010 */   sw       $s0, 0x10($sp)
/* D36574 80240284 305000FF */  andi      $s0, $v0, 0xff
/* D36578 80240288 0220202D */  daddu     $a0, $s1, $zero
/* D3657C 8024028C 3C05F5DE */  lui       $a1, 0xf5de
/* D36580 80240290 0C0B1EAF */  jal       get_variable
/* D36584 80240294 34A50289 */   ori      $a1, $a1, 0x289
/* D36588 80240298 304600FF */  andi      $a2, $v0, 0xff
/* D3658C 8024029C 240200FF */  addiu     $v0, $zero, 0xff
/* D36590 802402A0 12020006 */  beq       $s0, $v0, .L802402BC
/* D36594 802402A4 0220202D */   daddu    $a0, $s1, $zero
/* D36598 802402A8 3C05FD05 */  lui       $a1, 0xfd05
/* D3659C 802402AC 34A50F80 */  ori       $a1, $a1, 0xf80
/* D365A0 802402B0 00063200 */  sll       $a2, $a2, 8
/* D365A4 802402B4 080900B2 */  j         .L802402C8
/* D365A8 802402B8 00D03025 */   or       $a2, $a2, $s0
.L802402BC:
/* D365AC 802402BC 3C05FD05 */  lui       $a1, 0xfd05
/* D365B0 802402C0 34A50F80 */  ori       $a1, $a1, 0xf80
/* D365B4 802402C4 2406FFFF */  addiu     $a2, $zero, -1
.L802402C8:
/* D365B8 802402C8 0C0B2026 */  jal       set_variable
/* D365BC 802402CC 00000000 */   nop      
/* D365C0 802402D0 0220202D */  daddu     $a0, $s1, $zero
/* D365C4 802402D4 3C05F5DE */  lui       $a1, 0xf5de
/* D365C8 802402D8 0C0B1EAF */  jal       get_variable
/* D365CC 802402DC 34A5028A */   ori      $a1, $a1, 0x28a
/* D365D0 802402E0 305000FF */  andi      $s0, $v0, 0xff
/* D365D4 802402E4 0220202D */  daddu     $a0, $s1, $zero
/* D365D8 802402E8 3C05F5DE */  lui       $a1, 0xf5de
/* D365DC 802402EC 0C0B1EAF */  jal       get_variable
/* D365E0 802402F0 34A5028B */   ori      $a1, $a1, 0x28b
/* D365E4 802402F4 304600FF */  andi      $a2, $v0, 0xff
/* D365E8 802402F8 240200FF */  addiu     $v0, $zero, 0xff
/* D365EC 802402FC 12020006 */  beq       $s0, $v0, .L80240318
/* D365F0 80240300 0220202D */   daddu    $a0, $s1, $zero
/* D365F4 80240304 3C05FD05 */  lui       $a1, 0xfd05
/* D365F8 80240308 34A50F81 */  ori       $a1, $a1, 0xf81
/* D365FC 8024030C 00063200 */  sll       $a2, $a2, 8
/* D36600 80240310 080900C9 */  j         .L80240324
/* D36604 80240314 00D03025 */   or       $a2, $a2, $s0
.L80240318:
/* D36608 80240318 3C05FD05 */  lui       $a1, 0xfd05
/* D3660C 8024031C 34A50F81 */  ori       $a1, $a1, 0xf81
/* D36610 80240320 2406FFFF */  addiu     $a2, $zero, -1
.L80240324:
/* D36614 80240324 0C0B2026 */  jal       set_variable
/* D36618 80240328 00000000 */   nop      
/* D3661C 8024032C 0220202D */  daddu     $a0, $s1, $zero
/* D36620 80240330 3C05F5DE */  lui       $a1, 0xf5de
/* D36624 80240334 0C0B1EAF */  jal       get_variable
/* D36628 80240338 34A5028C */   ori      $a1, $a1, 0x28c
/* D3662C 8024033C 305000FF */  andi      $s0, $v0, 0xff
/* D36630 80240340 0220202D */  daddu     $a0, $s1, $zero
/* D36634 80240344 3C05F5DE */  lui       $a1, 0xf5de
/* D36638 80240348 0C0B1EAF */  jal       get_variable
/* D3663C 8024034C 34A5028D */   ori      $a1, $a1, 0x28d
/* D36640 80240350 304600FF */  andi      $a2, $v0, 0xff
/* D36644 80240354 240200FF */  addiu     $v0, $zero, 0xff
/* D36648 80240358 12020006 */  beq       $s0, $v0, .L80240374
/* D3664C 8024035C 0220202D */   daddu    $a0, $s1, $zero
/* D36650 80240360 3C05FD05 */  lui       $a1, 0xfd05
/* D36654 80240364 34A50F82 */  ori       $a1, $a1, 0xf82
/* D36658 80240368 00063200 */  sll       $a2, $a2, 8
/* D3665C 8024036C 080900E0 */  j         .L80240380
/* D36660 80240370 00D03025 */   or       $a2, $a2, $s0
.L80240374:
/* D36664 80240374 3C05FD05 */  lui       $a1, 0xfd05
/* D36668 80240378 34A50F82 */  ori       $a1, $a1, 0xf82
/* D3666C 8024037C 2406FFFF */  addiu     $a2, $zero, -1
.L80240380:
/* D36670 80240380 0C0B2026 */  jal       set_variable
/* D36674 80240384 00000000 */   nop      
/* D36678 80240388 8FBF0018 */  lw        $ra, 0x18($sp)
/* D3667C 8024038C 8FB10014 */  lw        $s1, 0x14($sp)
/* D36680 80240390 8FB00010 */  lw        $s0, 0x10($sp)
/* D36684 80240394 24020002 */  addiu     $v0, $zero, 2
/* D36688 80240398 03E00008 */  jr        $ra
/* D3668C 8024039C 27BD0020 */   addiu    $sp, $sp, 0x20
