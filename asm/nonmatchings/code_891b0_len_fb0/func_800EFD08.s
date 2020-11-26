.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EFD08
/* 891B8 800EFD08 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 891BC 800EFD0C AFB00010 */  sw        $s0, 0x10($sp)
/* 891C0 800EFD10 AFB10014 */  sw        $s1, 0x14($sp)
/* 891C4 800EFD14 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 891C8 800EFD18 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 891CC 800EFD1C AFBF001C */  sw        $ra, 0x1c($sp)
/* 891D0 800EFD20 AFB20018 */  sw        $s2, 0x18($sp)
/* 891D4 800EFD24 822200B4 */  lb        $v0, 0xb4($s1)
/* 891D8 800EFD28 24120003 */  addiu     $s2, $zero, 3
/* 891DC 800EFD2C 14520003 */  bne       $v0, $s2, .L800EFD3C
/* 891E0 800EFD30 0000802D */   daddu    $s0, $zero, $zero
/* 891E4 800EFD34 3C108011 */  lui       $s0, 0x8011
/* 891E8 800EFD38 8E109480 */  lw        $s0, -0x6b80($s0)
.L800EFD3C:
/* 891EC 800EFD3C 3C048016 */  lui       $a0, %hi(gCollisionStatus+0x2)
/* 891F0 800EFD40 9484A552 */  lhu       $a0, %lo(gCollisionStatus+0x2)($a0)
/* 891F4 800EFD44 0C016F6A */  jal       get_collider_type_by_id
/* 891F8 800EFD48 00000000 */   nop      
/* 891FC 800EFD4C 822300B4 */  lb        $v1, 0xb4($s1)
/* 89200 800EFD50 304200FF */  andi      $v0, $v0, 0xff
/* 89204 800EFD54 3C018011 */  lui       $at, 0x8011
/* 89208 800EFD58 AC229480 */  sw        $v0, -0x6b80($at)
/* 8920C 800EFD5C 54720001 */  bnel      $v1, $s2, .L800EFD64
/* 89210 800EFD60 0040802D */   daddu    $s0, $v0, $zero
.L800EFD64:
/* 89214 800EFD64 2402000A */  addiu     $v0, $zero, 0xa
/* 89218 800EFD68 14620008 */  bne       $v1, $v0, .L800EFD8C
/* 8921C 800EFD6C 00000000 */   nop      
/* 89220 800EFD70 8E220000 */  lw        $v0, ($s1)
/* 89224 800EFD74 04410005 */  bgez      $v0, .L800EFD8C
/* 89228 800EFD78 00000000 */   nop      
/* 8922C 800EFD7C 3C028011 */  lui       $v0, 0x8011
/* 89230 800EFD80 8C42CFF0 */  lw        $v0, -0x3010($v0)
/* 89234 800EFD84 3C018011 */  lui       $at, 0x8011
/* 89238 800EFD88 AC22CFF4 */  sw        $v0, -0x300c($at)
.L800EFD8C:
/* 8923C 800EFD8C 862200C0 */  lh        $v0, 0xc0($s1)
/* 89240 800EFD90 2603FFFF */  addiu     $v1, $s0, -1
/* 89244 800EFD94 3C018011 */  lui       $at, 0x8011
/* 89248 800EFD98 AC22CFF0 */  sw        $v0, -0x3010($at)
/* 8924C 800EFD9C 2C620009 */  sltiu     $v0, $v1, 9
/* 89250 800EFDA0 1040001A */  beqz      $v0, .L800EFE0C
/* 89254 800EFDA4 00031080 */   sll      $v0, $v1, 2
/* 89258 800EFDA8 3C018011 */  lui       $at, 0x8011
/* 8925C 800EFDAC 00220821 */  addu      $at, $at, $v0
/* 89260 800EFDB0 8C22C2E8 */  lw        $v0, -0x3d18($at)
/* 89264 800EFDB4 00400008 */  jr        $v0
/* 89268 800EFDB8 00000000 */   nop      
/* 8926C 800EFDBC 0C03C092 */  jal       func_800F0248
/* 89270 800EFDC0 00000000 */   nop      
/* 89274 800EFDC4 0803BF85 */  j         .L800EFE14
/* 89278 800EFDC8 00000000 */   nop      
/* 8927C 800EFDCC 0C03C124 */  jal       func_800F0490
/* 89280 800EFDD0 00000000 */   nop      
/* 89284 800EFDD4 0803BF85 */  j         .L800EFE14
/* 89288 800EFDD8 00000000 */   nop      
/* 8928C 800EFDDC 0C03C219 */  jal       func_800F0864
/* 89290 800EFDE0 00000000 */   nop      
/* 89294 800EFDE4 0803BF85 */  j         .L800EFE14
/* 89298 800EFDE8 00000000 */   nop      
/* 8929C 800EFDEC 0C03C27B */  jal       func_800F09EC
/* 892A0 800EFDF0 00000000 */   nop      
/* 892A4 800EFDF4 0803BF85 */  j         .L800EFE14
/* 892A8 800EFDF8 00000000 */   nop      
/* 892AC 800EFDFC 0C03C2CF */  jal       func_800F0B3C
/* 892B0 800EFE00 00000000 */   nop      
/* 892B4 800EFE04 0803BF85 */  j         .L800EFE14
/* 892B8 800EFE08 00000000 */   nop      
.L800EFE0C:
/* 892BC 800EFE0C 0C03BF8B */  jal       func_800EFE2C
/* 892C0 800EFE10 00000000 */   nop      
.L800EFE14:
/* 892C4 800EFE14 8FBF001C */  lw        $ra, 0x1c($sp)
/* 892C8 800EFE18 8FB20018 */  lw        $s2, 0x18($sp)
/* 892CC 800EFE1C 8FB10014 */  lw        $s1, 0x14($sp)
/* 892D0 800EFE20 8FB00010 */  lw        $s0, 0x10($sp)
/* 892D4 800EFE24 03E00008 */  jr        $ra
/* 892D8 800EFE28 27BD0020 */   addiu    $sp, $sp, 0x20
