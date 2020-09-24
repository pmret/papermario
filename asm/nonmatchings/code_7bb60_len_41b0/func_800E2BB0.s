.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E2BB0
/* 7C060 800E2BB0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7C064 800E2BB4 AFB00010 */  sw        $s0, 0x10($sp)
/* 7C068 800E2BB8 3C108011 */  lui       $s0, 0x8011
/* 7C06C 800E2BBC 2610EFC8 */  addiu     $s0, $s0, -0x1038
/* 7C070 800E2BC0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7C074 800E2BC4 C602007C */  lwc1      $f2, 0x7c($s0)
/* 7C078 800E2BC8 C6000078 */  lwc1      $f0, 0x78($s0)
/* 7C07C 800E2BCC 46001000 */  add.s     $f0, $f2, $f0
/* 7C080 800E2BD0 C604002C */  lwc1      $f4, 0x2c($s0)
/* 7C084 800E2BD4 4600203C */  c.lt.s    $f4, $f0
/* 7C088 800E2BD8 00000000 */  nop       
/* 7C08C 800E2BDC 45000026 */  bc1f      .L800E2C78
/* 7C090 800E2BE0 0000102D */   daddu    $v0, $zero, $zero
/* 7C094 800E2BE4 46041081 */  sub.s     $f2, $f2, $f4
/* 7C098 800E2BE8 3C014442 */  lui       $at, 0x4442
/* 7C09C 800E2BEC 34214000 */  ori       $at, $at, 0x4000
/* 7C0A0 800E2BF0 44810000 */  mtc1      $at, $f0
/* 7C0A4 800E2BF4 00000000 */  nop       
/* 7C0A8 800E2BF8 46001183 */  div.s     $f6, $f2, $f0
/* 7C0AC 800E2BFC 3C018011 */  lui       $at, 0x8011
/* 7C0B0 800E2C00 D422BD80 */  ldc1      $f2, -0x4280($at)
/* 7C0B4 800E2C04 46003021 */  cvt.d.s   $f0, $f6
/* 7C0B8 800E2C08 4622003C */  c.lt.d    $f0, $f2
/* 7C0BC 800E2C0C 00000000 */  nop       
/* 7C0C0 800E2C10 45000004 */  bc1f      .L800E2C24
/* 7C0C4 800E2C14 00000000 */   nop      
/* 7C0C8 800E2C18 3C01BEF0 */  lui       $at, 0xbef0
/* 7C0CC 800E2C1C 3421A3D7 */  ori       $at, $at, 0xa3d7
/* 7C0D0 800E2C20 44813000 */  mtc1      $at, $f6
.L800E2C24:
/* 7C0D4 800E2C24 3C018011 */  lui       $at, 0x8011
/* 7C0D8 800E2C28 D422BD88 */  ldc1      $f2, -0x4278($at)
/* 7C0DC 800E2C2C 46003021 */  cvt.d.s   $f0, $f6
/* 7C0E0 800E2C30 4620103C */  c.lt.d    $f2, $f0
/* 7C0E4 800E2C34 00000000 */  nop       
/* 7C0E8 800E2C38 45000004 */  bc1f      .L800E2C4C
/* 7C0EC 800E2C3C 00000000 */   nop      
/* 7C0F0 800E2C40 3C013A83 */  lui       $at, 0x3a83
/* 7C0F4 800E2C44 3421126F */  ori       $at, $at, 0x126f
/* 7C0F8 800E2C48 44813000 */  mtc1      $at, $f6
.L800E2C4C:
/* 7C0FC 800E2C4C C6000070 */  lwc1      $f0, 0x70($s0)
/* 7C100 800E2C50 46060000 */  add.s     $f0, $f0, $f6
/* 7C104 800E2C54 44801000 */  mtc1      $zero, $f2
/* 7C108 800E2C58 46002100 */  add.s     $f4, $f4, $f0
/* 7C10C 800E2C5C E6000070 */  swc1      $f0, 0x70($s0)
/* 7C110 800E2C60 4602003E */  c.le.s    $f0, $f2
/* 7C114 800E2C64 00000000 */  nop       
/* 7C118 800E2C68 45000011 */  bc1f      .L800E2CB0
/* 7C11C 800E2C6C E604002C */   swc1     $f4, 0x2c($s0)
/* 7C120 800E2C70 08038B2C */  j         .L800E2CB0
/* 7C124 800E2C74 24020001 */   addiu    $v0, $zero, 1
.L800E2C78:
/* 7C128 800E2C78 C6000070 */  lwc1      $f0, 0x70($s0)
/* 7C12C 800E2C7C 3C018011 */  lui       $at, 0x8011
/* 7C130 800E2C80 D422BD90 */  ldc1      $f2, -0x4270($at)
/* 7C134 800E2C84 46000021 */  cvt.d.s   $f0, $f0
/* 7C138 800E2C88 46220000 */  add.d     $f0, $f0, $f2
/* 7C13C 800E2C8C 44801000 */  mtc1      $zero, $f2
/* 7C140 800E2C90 46200020 */  cvt.s.d   $f0, $f0
/* 7C144 800E2C94 4602003E */  c.le.s    $f0, $f2
/* 7C148 800E2C98 00000000 */  nop       
/* 7C14C 800E2C9C 45000002 */  bc1f      .L800E2CA8
/* 7C150 800E2CA0 E6000070 */   swc1     $f0, 0x70($s0)
/* 7C154 800E2CA4 24020001 */  addiu     $v0, $zero, 1
.L800E2CA8:
/* 7C158 800E2CA8 46002000 */  add.s     $f0, $f4, $f0
/* 7C15C 800E2CAC E600002C */  swc1      $f0, 0x2c($s0)
.L800E2CB0:
/* 7C160 800E2CB0 10400015 */  beqz      $v0, .L800E2D08
/* 7C164 800E2CB4 00000000 */   nop      
/* 7C168 800E2CB8 0C0389AC */  jal       func_800E26B0
/* 7C16C 800E2CBC 00000000 */   nop      
/* 7C170 800E2CC0 3C013DEA */  lui       $at, 0x3dea
/* 7C174 800E2CC4 3421161E */  ori       $at, $at, 0x161e
/* 7C178 800E2CC8 44810000 */  mtc1      $at, $f0
/* 7C17C 800E2CCC 3C01BE92 */  lui       $at, 0xbe92
/* 7C180 800E2CD0 3421FEC5 */  ori       $at, $at, 0xfec5
/* 7C184 800E2CD4 44811000 */  mtc1      $at, $f2
/* 7C188 800E2CD8 3C01BE3A */  lui       $at, 0xbe3a
/* 7C18C 800E2CDC 3421ACDA */  ori       $at, $at, 0xacda
/* 7C190 800E2CE0 44812000 */  mtc1      $at, $f4
/* 7C194 800E2CE4 3C013C3C */  lui       $at, 0x3c3c
/* 7C198 800E2CE8 3421BE62 */  ori       $at, $at, 0xbe62
/* 7C19C 800E2CEC 44813000 */  mtc1      $at, $f6
/* 7C1A0 800E2CF0 24040008 */  addiu     $a0, $zero, 8
/* 7C1A4 800E2CF4 E6000070 */  swc1      $f0, 0x70($s0)
/* 7C1A8 800E2CF8 E6020074 */  swc1      $f2, 0x74($s0)
/* 7C1AC 800E2CFC E6040078 */  swc1      $f4, 0x78($s0)
/* 7C1B0 800E2D00 0C039769 */  jal       set_action_state
/* 7C1B4 800E2D04 E606007C */   swc1     $f6, 0x7c($s0)
.L800E2D08:
/* 7C1B8 800E2D08 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7C1BC 800E2D0C 8FB00010 */  lw        $s0, 0x10($sp)
/* 7C1C0 800E2D10 03E00008 */  jr        $ra
/* 7C1C4 800E2D14 27BD0018 */   addiu    $sp, $sp, 0x18
