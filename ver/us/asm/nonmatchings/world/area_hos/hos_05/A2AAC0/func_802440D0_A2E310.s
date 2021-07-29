.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8024F240_A39480
.word L80244104_A2E344, L80244118_A2E358, L80244160_A2E3A0, L80244244_A2E484, L80244288_A2E4C8, L802443B0_A2E5F0, L80244438_A2E678, 0

.section .text

glabel func_802440D0_A2E310
/* A2E310 802440D0 3C038025 */  lui       $v1, %hi(D_8024AAB0_A34CF0)
/* A2E314 802440D4 8C63AAB0 */  lw        $v1, %lo(D_8024AAB0_A34CF0)($v1)
/* A2E318 802440D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2E31C 802440DC AFBF0014 */  sw        $ra, 0x14($sp)
/* A2E320 802440E0 2C620007 */  sltiu     $v0, $v1, 7
/* A2E324 802440E4 104000D4 */  beqz      $v0, L80244438_A2E678
/* A2E328 802440E8 AFB00010 */   sw       $s0, 0x10($sp)
/* A2E32C 802440EC 00031080 */  sll       $v0, $v1, 2
/* A2E330 802440F0 3C018025 */  lui       $at, %hi(jtbl_8024F240_A39480)
/* A2E334 802440F4 00220821 */  addu      $at, $at, $v0
/* A2E338 802440F8 8C22F240 */  lw        $v0, %lo(jtbl_8024F240_A39480)($at)
/* A2E33C 802440FC 00400008 */  jr        $v0
/* A2E340 80244100 00000000 */   nop
glabel L80244104_A2E344
/* A2E344 80244104 3C048025 */  lui       $a0, %hi(D_8024AAB0_A34CF0)
/* A2E348 80244108 2484AAB0 */  addiu     $a0, $a0, %lo(D_8024AAB0_A34CF0)
/* A2E34C 8024410C 3C038025 */  lui       $v1, %hi(D_8024AAB4_A34CF4)
/* A2E350 80244110 08091097 */  j         .L8024425C
/* A2E354 80244114 8C63AAB4 */   lw       $v1, %lo(D_8024AAB4_A34CF4)($v1)
glabel L80244118_A2E358
/* A2E358 80244118 3C068025 */  lui       $a2, %hi(D_8024AAB8_A34CF8)
/* A2E35C 8024411C 24C6AAB8 */  addiu     $a2, $a2, %lo(D_8024AAB8_A34CF8)
/* A2E360 80244120 8CC20000 */  lw        $v0, ($a2)
/* A2E364 80244124 10400003 */  beqz      $v0, .L80244134
/* A2E368 80244128 2442FFFF */   addiu    $v0, $v0, -1
/* A2E36C 8024412C 08091110 */  j         .L80244440
/* A2E370 80244130 ACC20000 */   sw       $v0, ($a2)
.L80244134:
/* A2E374 80244134 240400B0 */  addiu     $a0, $zero, 0xb0
/* A2E378 80244138 3C028025 */  lui       $v0, %hi(D_8024AAB0_A34CF0)
/* A2E37C 8024413C 2442AAB0 */  addiu     $v0, $v0, %lo(D_8024AAB0_A34CF0)
/* A2E380 80244140 8C430000 */  lw        $v1, ($v0)
/* A2E384 80244144 2405001A */  addiu     $a1, $zero, 0x1a
/* A2E388 80244148 ACC50000 */  sw        $a1, ($a2)
/* A2E38C 8024414C 24630001 */  addiu     $v1, $v1, 1
/* A2E390 80244150 0C05272D */  jal       sfx_play_sound
/* A2E394 80244154 AC430000 */   sw       $v1, ($v0)
/* A2E398 80244158 08091111 */  j         .L80244444
/* A2E39C 8024415C 0000102D */   daddu    $v0, $zero, $zero
glabel L80244160_A2E3A0
/* A2E3A0 80244160 3C058025 */  lui       $a1, %hi(D_8024AAB8_A34CF8)
/* A2E3A4 80244164 24A5AAB8 */  addiu     $a1, $a1, %lo(D_8024AAB8_A34CF8)
/* A2E3A8 80244168 8CA30000 */  lw        $v1, ($a1)
/* A2E3AC 8024416C 10600008 */  beqz      $v1, .L80244190
/* A2E3B0 80244170 2463FFFF */   addiu    $v1, $v1, -1
/* A2E3B4 80244174 3C048025 */  lui       $a0, %hi(D_8024AA20_A34C60)
/* A2E3B8 80244178 8C84AA20 */  lw        $a0, %lo(D_8024AA20_A34C60)($a0)
/* A2E3BC 8024417C 84820058 */  lh        $v0, 0x58($a0)
/* A2E3C0 80244180 1040009E */  beqz      $v0, .L802443FC
/* A2E3C4 80244184 ACA30000 */   sw       $v1, ($a1)
/* A2E3C8 80244188 080910F7 */  j         .L802443DC
/* A2E3CC 8024418C 24020019 */   addiu    $v0, $zero, 0x19
.L80244190:
/* A2E3D0 80244190 3C038025 */  lui       $v1, %hi(D_8024AAB4_A34CF4)
/* A2E3D4 80244194 2463AAB4 */  addiu     $v1, $v1, %lo(D_8024AAB4_A34CF4)
/* A2E3D8 80244198 8C640000 */  lw        $a0, ($v1)
/* A2E3DC 8024419C 24820001 */  addiu     $v0, $a0, 1
/* A2E3E0 802441A0 24850002 */  addiu     $a1, $a0, 2
/* A2E3E4 802441A4 AC620000 */  sw        $v0, ($v1)
/* A2E3E8 802441A8 28A20005 */  slti      $v0, $a1, 5
/* A2E3EC 802441AC 10400011 */  beqz      $v0, .L802441F4
/* A2E3F0 802441B0 00000000 */   nop
/* A2E3F4 802441B4 3C108025 */  lui       $s0, %hi(D_8024AA20_A34C60)
/* A2E3F8 802441B8 2610AA20 */  addiu     $s0, $s0, %lo(D_8024AA20_A34C60)
/* A2E3FC 802441BC 8E020000 */  lw        $v0, ($s0)
/* A2E400 802441C0 0C090FB4 */  jal       func_80243ED0_A2E110
/* A2E404 802441C4 84440058 */   lh       $a0, 0x58($v0)
/* A2E408 802441C8 8E020000 */  lw        $v0, ($s0)
/* A2E40C 802441CC 94430058 */  lhu       $v1, 0x58($v0)
/* A2E410 802441D0 3C018025 */  lui       $at, %hi(D_8024AAB0_A34CF0)
/* A2E414 802441D4 AC20AAB0 */  sw        $zero, %lo(D_8024AAB0_A34CF0)($at)
/* A2E418 802441D8 A440003C */  sh        $zero, 0x3c($v0)
/* A2E41C 802441DC A440003E */  sh        $zero, 0x3e($v0)
/* A2E420 802441E0 A4400040 */  sh        $zero, 0x40($v0)
/* A2E424 802441E4 A4400042 */  sh        $zero, 0x42($v0)
/* A2E428 802441E8 38630001 */  xori      $v1, $v1, 1
/* A2E42C 802441EC 08091110 */  j         .L80244440
/* A2E430 802441F0 A4430058 */   sh       $v1, 0x58($v0)
.L802441F4:
/* A2E434 802441F4 3C038025 */  lui       $v1, %hi(D_8024AA20_A34C60)
/* A2E438 802441F8 8C63AA20 */  lw        $v1, %lo(D_8024AA20_A34C60)($v1)
/* A2E43C 802441FC 84620058 */  lh        $v0, 0x58($v1)
/* A2E440 80244200 54400004 */  bnel      $v0, $zero, .L80244214
/* A2E444 80244204 A460003C */   sh       $zero, 0x3c($v1)
/* A2E448 80244208 A4600040 */  sh        $zero, 0x40($v1)
/* A2E44C 8024420C 08091086 */  j         .L80244218
/* A2E450 80244210 A4600042 */   sh       $zero, 0x42($v1)
.L80244214:
/* A2E454 80244214 A460003E */  sh        $zero, 0x3e($v1)
.L80244218:
/* A2E458 80244218 3C04800B */  lui       $a0, %hi(gCameras)
/* A2E45C 8024421C 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* A2E460 80244220 3C058025 */  lui       $a1, %hi(D_8024AAB0_A34CF0)
/* A2E464 80244224 24A5AAB0 */  addiu     $a1, $a1, %lo(D_8024AAB0_A34CF0)
/* A2E468 80244228 94820000 */  lhu       $v0, ($a0)
/* A2E46C 8024422C 8CA30000 */  lw        $v1, ($a1)
/* A2E470 80244230 3042FFFD */  andi      $v0, $v0, 0xfffd
/* A2E474 80244234 24630001 */  addiu     $v1, $v1, 1
/* A2E478 80244238 A4820000 */  sh        $v0, ($a0)
/* A2E47C 8024423C 08091110 */  j         .L80244440
/* A2E480 80244240 ACA30000 */   sw       $v1, ($a1)
glabel L80244244_A2E484
/* A2E484 80244244 3C038025 */  lui       $v1, %hi(D_8024AAB4_A34CF4)
/* A2E488 80244248 8C63AAB4 */  lw        $v1, %lo(D_8024AAB4_A34CF4)($v1)
/* A2E48C 8024424C 3C048025 */  lui       $a0, %hi(D_8024AAB0_A34CF0)
/* A2E490 80244250 2484AAB0 */  addiu     $a0, $a0, %lo(D_8024AAB0_A34CF0)
/* A2E494 80244254 3C018025 */  lui       $at, %hi(D_8024AABC_A34CFC)
/* A2E498 80244258 AC20AABC */  sw        $zero, %lo(D_8024AABC_A34CFC)($at)
.L8024425C:
/* A2E49C 8024425C 8C820000 */  lw        $v0, ($a0)
/* A2E4A0 80244260 00031880 */  sll       $v1, $v1, 2
/* A2E4A4 80244264 3C018025 */  lui       $at, %hi(D_8024AAC0_A34D00)
/* A2E4A8 80244268 00230821 */  addu      $at, $at, $v1
/* A2E4AC 8024426C 8C23AAC0 */  lw        $v1, %lo(D_8024AAC0_A34D00)($at)
/* A2E4B0 80244270 24420001 */  addiu     $v0, $v0, 1
/* A2E4B4 80244274 AC820000 */  sw        $v0, ($a0)
/* A2E4B8 80244278 3C018025 */  lui       $at, %hi(D_8024AAB8_A34CF8)
/* A2E4BC 8024427C AC23AAB8 */  sw        $v1, %lo(D_8024AAB8_A34CF8)($at)
/* A2E4C0 80244280 08091111 */  j         .L80244444
/* A2E4C4 80244284 0000102D */   daddu    $v0, $zero, $zero
glabel L80244288_A2E4C8
/* A2E4C8 80244288 3C068025 */  lui       $a2, %hi(D_8024AAB8_A34CF8)
/* A2E4CC 8024428C 24C6AAB8 */  addiu     $a2, $a2, %lo(D_8024AAB8_A34CF8)
/* A2E4D0 80244290 8CC30000 */  lw        $v1, ($a2)
/* A2E4D4 80244294 10600038 */  beqz      $v1, .L80244378
/* A2E4D8 80244298 240400B0 */   addiu    $a0, $zero, 0xb0
/* A2E4DC 8024429C 3C028025 */  lui       $v0, %hi(D_8024AAB4_A34CF4)
/* A2E4E0 802442A0 8C42AAB4 */  lw        $v0, %lo(D_8024AAB4_A34CF4)($v0)
/* A2E4E4 802442A4 00021080 */  sll       $v0, $v0, 2
/* A2E4E8 802442A8 3C018025 */  lui       $at, %hi(D_8024AAC0_A34D00)
/* A2E4EC 802442AC 00220821 */  addu      $at, $at, $v0
/* A2E4F0 802442B0 8C22AAC0 */  lw        $v0, %lo(D_8024AAC0_A34D00)($at)
/* A2E4F4 802442B4 2442FEF4 */  addiu     $v0, $v0, -0x10c
/* A2E4F8 802442B8 0062102A */  slt       $v0, $v1, $v0
/* A2E4FC 802442BC 10400028 */  beqz      $v0, .L80244360
/* A2E500 802442C0 00000000 */   nop
/* A2E504 802442C4 3C048025 */  lui       $a0, %hi(D_8024AABC_A34CFC)
/* A2E508 802442C8 8C84AABC */  lw        $a0, %lo(D_8024AABC_A34CFC)($a0)
/* A2E50C 802442CC 2C820140 */  sltiu     $v0, $a0, 0x140
/* A2E510 802442D0 1040000B */  beqz      $v0, .L80244300
/* A2E514 802442D4 2483FEC0 */   addiu    $v1, $a0, -0x140
/* A2E518 802442D8 3C028025 */  lui       $v0, %hi(D_8024AA20_A34C60)
/* A2E51C 802442DC 8C42AA20 */  lw        $v0, %lo(D_8024AA20_A34C60)($v0)
/* A2E520 802442E0 3C038025 */  lui       $v1, %hi(D_8024AC7C_A34EBC)
/* A2E524 802442E4 9463AC7C */  lhu       $v1, %lo(D_8024AC7C_A34EBC)($v1)
/* A2E528 802442E8 A4430044 */  sh        $v1, 0x44($v0)
/* A2E52C 802442EC 3C038025 */  lui       $v1, %hi(D_8024AB3C_A34D7C)
/* A2E530 802442F0 00641821 */  addu      $v1, $v1, $a0
/* A2E534 802442F4 9063AB3C */  lbu       $v1, %lo(D_8024AB3C_A34D7C)($v1)
/* A2E538 802442F8 080910D3 */  j         .L8024434C
/* A2E53C 802442FC A4430046 */   sh       $v1, 0x46($v0)
.L80244300:
/* A2E540 80244300 2C62000F */  sltiu     $v0, $v1, 0xf
/* A2E544 80244304 10400011 */  beqz      $v0, .L8024434C
/* A2E548 80244308 00032040 */   sll      $a0, $v1, 1
/* A2E54C 8024430C 3C058025 */  lui       $a1, %hi(D_8024AA20_A34C60)
/* A2E550 80244310 8CA5AA20 */  lw        $a1, %lo(D_8024AA20_A34C60)($a1)
/* A2E554 80244314 3C028025 */  lui       $v0, %hi(D_8024AC7C_A34EBC)
/* A2E558 80244318 00441021 */  addu      $v0, $v0, $a0
/* A2E55C 8024431C 9442AC7C */  lhu       $v0, %lo(D_8024AC7C_A34EBC)($v0)
/* A2E560 80244320 A4A20044 */  sh        $v0, 0x44($a1)
/* A2E564 80244324 2C62000D */  sltiu     $v0, $v1, 0xd
/* A2E568 80244328 10400008 */  beqz      $v0, .L8024434C
/* A2E56C 8024432C 00000000 */   nop
/* A2E570 80244330 3C028025 */  lui       $v0, %hi(D_8024AC7B_A34EBB)
/* A2E574 80244334 9042AC7B */  lbu       $v0, %lo(D_8024AC7B_A34EBB)($v0)
/* A2E578 80244338 3C038025 */  lui       $v1, %hi(D_8024AC9C_A34EDC)
/* A2E57C 8024433C 00641821 */  addu      $v1, $v1, $a0
/* A2E580 80244340 9463AC9C */  lhu       $v1, %lo(D_8024AC9C_A34EDC)($v1)
/* A2E584 80244344 00431021 */  addu      $v0, $v0, $v1
/* A2E588 80244348 A4A20046 */  sh        $v0, 0x46($a1)
.L8024434C:
/* A2E58C 8024434C 3C038025 */  lui       $v1, %hi(D_8024AABC_A34CFC)
/* A2E590 80244350 2463AABC */  addiu     $v1, $v1, %lo(D_8024AABC_A34CFC)
/* A2E594 80244354 8C620000 */  lw        $v0, ($v1)
/* A2E598 80244358 24420001 */  addiu     $v0, $v0, 1
/* A2E59C 8024435C AC620000 */  sw        $v0, ($v1)
.L80244360:
/* A2E5A0 80244360 3C038025 */  lui       $v1, %hi(D_8024AAB8_A34CF8)
/* A2E5A4 80244364 2463AAB8 */  addiu     $v1, $v1, %lo(D_8024AAB8_A34CF8)
/* A2E5A8 80244368 8C620000 */  lw        $v0, ($v1)
/* A2E5AC 8024436C 2442FFFF */  addiu     $v0, $v0, -1
/* A2E5B0 80244370 08091110 */  j         .L80244440
/* A2E5B4 80244374 AC620000 */   sw       $v0, ($v1)
.L80244378:
/* A2E5B8 80244378 3C058025 */  lui       $a1, %hi(D_8024AAB0_A34CF0)
/* A2E5BC 8024437C 24A5AAB0 */  addiu     $a1, $a1, %lo(D_8024AAB0_A34CF0)
/* A2E5C0 80244380 8CA20000 */  lw        $v0, ($a1)
/* A2E5C4 80244384 2403001A */  addiu     $v1, $zero, 0x1a
/* A2E5C8 80244388 ACC30000 */  sw        $v1, ($a2)
/* A2E5CC 8024438C 24420001 */  addiu     $v0, $v0, 1
/* A2E5D0 80244390 ACA20000 */  sw        $v0, ($a1)
/* A2E5D4 80244394 3C038025 */  lui       $v1, %hi(D_8024AA20_A34C60)
/* A2E5D8 80244398 8C63AA20 */  lw        $v1, %lo(D_8024AA20_A34C60)($v1)
/* A2E5DC 8024439C 240200FF */  addiu     $v0, $zero, 0xff
/* A2E5E0 802443A0 0C05272D */  jal       sfx_play_sound
/* A2E5E4 802443A4 A462005C */   sh       $v0, 0x5c($v1)
/* A2E5E8 802443A8 08091111 */  j         .L80244444
/* A2E5EC 802443AC 0000102D */   daddu    $v0, $zero, $zero
glabel L802443B0_A2E5F0
/* A2E5F0 802443B0 3C058025 */  lui       $a1, %hi(D_8024AAB8_A34CF8)
/* A2E5F4 802443B4 24A5AAB8 */  addiu     $a1, $a1, %lo(D_8024AAB8_A34CF8)
/* A2E5F8 802443B8 8CA30000 */  lw        $v1, ($a1)
/* A2E5FC 802443BC 10600018 */  beqz      $v1, .L80244420
/* A2E600 802443C0 2463FFFF */   addiu    $v1, $v1, -1
/* A2E604 802443C4 3C048025 */  lui       $a0, %hi(D_8024AA20_A34C60)
/* A2E608 802443C8 8C84AA20 */  lw        $a0, %lo(D_8024AA20_A34C60)($a0)
/* A2E60C 802443CC 84820058 */  lh        $v0, 0x58($a0)
/* A2E610 802443D0 1440000A */  bnez      $v0, .L802443FC
/* A2E614 802443D4 ACA30000 */   sw       $v1, ($a1)
/* A2E618 802443D8 24020019 */  addiu     $v0, $zero, 0x19
.L802443DC:
/* A2E61C 802443DC 00431023 */  subu      $v0, $v0, $v1
/* A2E620 802443E0 00021080 */  sll       $v0, $v0, 2
/* A2E624 802443E4 3C018025 */  lui       $at, %hi(D_8024AAD6_A34D16)
/* A2E628 802443E8 00220821 */  addu      $at, $at, $v0
/* A2E62C 802443EC 9422AAD6 */  lhu       $v0, %lo(D_8024AAD6_A34D16)($at)
/* A2E630 802443F0 A4800042 */  sh        $zero, 0x42($a0)
/* A2E634 802443F4 08091110 */  j         .L80244440
/* A2E638 802443F8 A4820040 */   sh       $v0, 0x40($a0)
.L802443FC:
/* A2E63C 802443FC 24020019 */  addiu     $v0, $zero, 0x19
/* A2E640 80244400 00431023 */  subu      $v0, $v0, $v1
/* A2E644 80244404 00021080 */  sll       $v0, $v0, 2
/* A2E648 80244408 3C018025 */  lui       $at, %hi(D_8024AAD6_A34D16)
/* A2E64C 8024440C 00220821 */  addu      $at, $at, $v0
/* A2E650 80244410 9422AAD6 */  lhu       $v0, %lo(D_8024AAD6_A34D16)($at)
/* A2E654 80244414 A480003E */  sh        $zero, 0x3e($a0)
/* A2E658 80244418 08091110 */  j         .L80244440
/* A2E65C 8024441C A482003C */   sh       $v0, 0x3c($a0)
.L80244420:
/* A2E660 80244420 3C038025 */  lui       $v1, %hi(D_8024AAB0_A34CF0)
/* A2E664 80244424 2463AAB0 */  addiu     $v1, $v1, %lo(D_8024AAB0_A34CF0)
/* A2E668 80244428 8C620000 */  lw        $v0, ($v1)
/* A2E66C 8024442C 24420001 */  addiu     $v0, $v0, 1
/* A2E670 80244430 08091110 */  j         .L80244440
/* A2E674 80244434 AC620000 */   sw       $v0, ($v1)
glabel L80244438_A2E678
/* A2E678 80244438 08091111 */  j         .L80244444
/* A2E67C 8024443C 24020001 */   addiu    $v0, $zero, 1
.L80244440:
/* A2E680 80244440 0000102D */  daddu     $v0, $zero, $zero
.L80244444:
/* A2E684 80244444 8FBF0014 */  lw        $ra, 0x14($sp)
/* A2E688 80244448 8FB00010 */  lw        $s0, 0x10($sp)
/* A2E68C 8024444C 03E00008 */  jr        $ra
/* A2E690 80244450 27BD0018 */   addiu    $sp, $sp, 0x18
