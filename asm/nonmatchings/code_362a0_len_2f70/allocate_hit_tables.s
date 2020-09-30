.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel allocate_hit_tables
/* 362A0 8005AEA0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 362A4 8005AEA4 AFB00010 */  sw        $s0, 0x10($sp)
/* 362A8 8005AEA8 3C10800B */  lui       $s0, 0x800b
/* 362AC 8005AEAC 261042E0 */  addiu     $s0, $s0, 0x42e0
/* 362B0 8005AEB0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 362B4 8005AEB4 8604000C */  lh        $a0, 0xc($s0)
/* 362B8 8005AEB8 0C00AB0A */  jal       general_heap_malloc
/* 362BC 8005AEBC 000420C0 */   sll      $a0, $a0, 3
/* 362C0 8005AEC0 0040202D */  daddu     $a0, $v0, $zero
/* 362C4 8005AEC4 8602000C */  lh        $v0, 0xc($s0)
/* 362C8 8005AEC8 3C01800A */  lui       $at, 0x800a
/* 362CC 8005AECC AC244264 */  sw        $a0, 0x4264($at)
/* 362D0 8005AED0 1840000E */  blez      $v0, .L8005AF0C
/* 362D4 8005AED4 0000282D */   daddu    $a1, $zero, $zero
/* 362D8 8005AED8 00A0302D */  daddu     $a2, $a1, $zero
.L8005AEDC:
/* 362DC 8005AEDC 8E020004 */  lw        $v0, 4($s0)
/* 362E0 8005AEE0 00461821 */  addu      $v1, $v0, $a2
/* 362E4 8005AEE4 8C620000 */  lw        $v0, ($v1)
/* 362E8 8005AEE8 24A50001 */  addiu     $a1, $a1, 1
/* 362EC 8005AEEC AC820000 */  sw        $v0, ($a0)
/* 362F0 8005AEF0 94620008 */  lhu       $v0, 8($v1)
/* 362F4 8005AEF4 24C6001C */  addiu     $a2, $a2, 0x1c
/* 362F8 8005AEF8 A4820004 */  sh        $v0, 4($a0)
/* 362FC 8005AEFC 8602000C */  lh        $v0, 0xc($s0)
/* 36300 8005AF00 00A2102A */  slt       $v0, $a1, $v0
/* 36304 8005AF04 1440FFF5 */  bnez      $v0, .L8005AEDC
/* 36308 8005AF08 24840008 */   addiu    $a0, $a0, 8
.L8005AF0C:
/* 3630C 8005AF0C 3C10800E */  lui       $s0, 0x800e
/* 36310 8005AF10 261091D0 */  addiu     $s0, $s0, -0x6e30
/* 36314 8005AF14 8604000C */  lh        $a0, 0xc($s0)
/* 36318 8005AF18 0C00AB0A */  jal       general_heap_malloc
/* 3631C 8005AF1C 000420C0 */   sll      $a0, $a0, 3
/* 36320 8005AF20 0040202D */  daddu     $a0, $v0, $zero
/* 36324 8005AF24 8602000C */  lh        $v0, 0xc($s0)
/* 36328 8005AF28 3C01800A */  lui       $at, 0x800a
/* 3632C 8005AF2C AC244268 */  sw        $a0, 0x4268($at)
/* 36330 8005AF30 1840000E */  blez      $v0, .L8005AF6C
/* 36334 8005AF34 0000282D */   daddu    $a1, $zero, $zero
/* 36338 8005AF38 00A0302D */  daddu     $a2, $a1, $zero
.L8005AF3C:
/* 3633C 8005AF3C 8E020004 */  lw        $v0, 4($s0)
/* 36340 8005AF40 00461821 */  addu      $v1, $v0, $a2
/* 36344 8005AF44 8C620000 */  lw        $v0, ($v1)
/* 36348 8005AF48 24A50001 */  addiu     $a1, $a1, 1
/* 3634C 8005AF4C AC820000 */  sw        $v0, ($a0)
/* 36350 8005AF50 94620008 */  lhu       $v0, 8($v1)
/* 36354 8005AF54 24C6001C */  addiu     $a2, $a2, 0x1c
/* 36358 8005AF58 A4820004 */  sh        $v0, 4($a0)
/* 3635C 8005AF5C 8602000C */  lh        $v0, 0xc($s0)
/* 36360 8005AF60 00A2102A */  slt       $v0, $a1, $v0
/* 36364 8005AF64 1440FFF5 */  bnez      $v0, .L8005AF3C
/* 36368 8005AF68 24840008 */   addiu    $a0, $a0, 8
.L8005AF6C:
/* 3636C 8005AF6C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 36370 8005AF70 8FB00010 */  lw        $s0, 0x10($sp)
/* 36374 8005AF74 3C01800E */  lui       $at, 0x800e
/* 36378 8005AF78 A42091DC */  sh        $zero, -0x6e24($at)
/* 3637C 8005AF7C 03E00008 */  jr        $ra
/* 36380 8005AF80 27BD0018 */   addiu    $sp, $sp, 0x18
