.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E0294
/* 79744 800E0294 3C028016 */  lui       $v0, %hi(D_8015A57A)
/* 79748 800E0298 8042A57A */  lb        $v0, %lo(D_8015A57A)($v0)
/* 7974C 800E029C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 79750 800E02A0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 79754 800E02A4 10400016 */  beqz      $v0, .L800E0300
/* 79758 800E02A8 AFB00010 */   sw       $s0, 0x10($sp)
/* 7975C 800E02AC 3C108011 */  lui       $s0, %hi(D_8010C93C)
/* 79760 800E02B0 2610C93C */  addiu     $s0, $s0, %lo(D_8010C93C)
/* 79764 800E02B4 8E020000 */  lw        $v0, ($s0)
/* 79768 800E02B8 14400015 */  bnez      $v0, .L800E0310
/* 7976C 800E02BC 00000000 */   nop
/* 79770 800E02C0 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 79774 800E02C4 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 79778 800E02C8 8C420004 */  lw        $v0, 4($v0)
/* 7977C 800E02CC 30420030 */  andi      $v0, $v0, 0x30
/* 79780 800E02D0 1440000B */  bnez      $v0, .L800E0300
/* 79784 800E02D4 00000000 */   nop
/* 79788 800E02D8 3C06802B */  lui       $a2, 0x802b
/* 7978C 800E02DC 3C0400E2 */  lui       $a0, 0xe2
/* 79790 800E02E0 248425B0 */  addiu     $a0, $a0, 0x25b0
/* 79794 800E02E4 3C0500E2 */  lui       $a1, 0xe2
/* 79798 800E02E8 24A53260 */  addiu     $a1, $a1, 0x3260
/* 7979C 800E02EC 0C00A5CF */  jal       dma_copy
/* 797A0 800E02F0 34C67000 */   ori      $a2, $a2, 0x7000
/* 797A4 800E02F4 3C02802B */  lui       $v0, %hi(D_802B72C0)
/* 797A8 800E02F8 244272C0 */  addiu     $v0, $v0, %lo(D_802B72C0)
/* 797AC 800E02FC AE020000 */  sw        $v0, ($s0)
.L800E0300:
/* 797B0 800E0300 3C028011 */  lui       $v0, %hi(D_8010C93C)
/* 797B4 800E0304 8C42C93C */  lw        $v0, %lo(D_8010C93C)($v0)
/* 797B8 800E0308 10400005 */  beqz      $v0, .L800E0320
/* 797BC 800E030C 00000000 */   nop
.L800E0310:
/* 797C0 800E0310 3C028011 */  lui       $v0, %hi(D_8010C93C)
/* 797C4 800E0314 8C42C93C */  lw        $v0, %lo(D_8010C93C)($v0)
/* 797C8 800E0318 0040F809 */  jalr      $v0
/* 797CC 800E031C 00000000 */   nop
.L800E0320:
/* 797D0 800E0320 8FBF0014 */  lw        $ra, 0x14($sp)
/* 797D4 800E0324 8FB00010 */  lw        $s0, 0x10($sp)
/* 797D8 800E0328 03E00008 */  jr        $ra
/* 797DC 800E032C 27BD0018 */   addiu    $sp, $sp, 0x18
