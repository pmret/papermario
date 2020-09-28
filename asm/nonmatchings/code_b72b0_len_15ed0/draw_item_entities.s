.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel draw_item_entities
/* C9380 80132C80 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* C9384 80132C84 AFB00020 */  sw        $s0, 0x20($sp)
/* C9388 80132C88 27B00010 */  addiu     $s0, $sp, 0x10
/* C938C 80132C8C AFB10024 */  sw        $s1, 0x24($sp)
/* C9390 80132C90 0000882D */  daddu     $s1, $zero, $zero
/* C9394 80132C94 AFB50034 */  sw        $s5, 0x34($sp)
/* C9398 80132C98 24150001 */  addiu     $s5, $zero, 1
/* C939C 80132C9C AFB40030 */  sw        $s4, 0x30($sp)
/* C93A0 80132CA0 3C140010 */  lui       $s4, 0x10
/* C93A4 80132CA4 AFB3002C */  sw        $s3, 0x2c($sp)
/* C93A8 80132CA8 2413FFFF */  addiu     $s3, $zero, -1
/* C93AC 80132CAC AFB20028 */  sw        $s2, 0x28($sp)
/* C93B0 80132CB0 3C120008 */  lui       $s2, 8
/* C93B4 80132CB4 AFBF0038 */  sw        $ra, 0x38($sp)
.L80132CB8:
/* C93B8 80132CB8 3C038015 */  lui       $v1, 0x8015
/* C93BC 80132CBC 8C6365A0 */  lw        $v1, 0x65a0($v1)
/* C93C0 80132CC0 00111080 */  sll       $v0, $s1, 2
/* C93C4 80132CC4 00431021 */  addu      $v0, $v0, $v1
/* C93C8 80132CC8 8C450000 */  lw        $a1, ($v0)
/* C93CC 80132CCC 50A00025 */  beql      $a1, $zero, .L80132D64
/* C93D0 80132CD0 26310001 */   addiu    $s1, $s1, 1
/* C93D4 80132CD4 8CA40000 */  lw        $a0, ($a1)
/* C93D8 80132CD8 10800021 */  beqz      $a0, .L80132D60
/* C93DC 80132CDC 30820040 */   andi     $v0, $a0, 0x40
/* C93E0 80132CE0 54400020 */  bnel      $v0, $zero, .L80132D64
/* C93E4 80132CE4 26310001 */   addiu    $s1, $s1, 1
/* C93E8 80132CE8 3C02800A */  lui       $v0, 0x800a
/* C93EC 80132CEC 8442A634 */  lh        $v0, -0x59cc($v0)
/* C93F0 80132CF0 00551004 */  sllv      $v0, $s5, $v0
/* C93F4 80132CF4 00821024 */  and       $v0, $a0, $v0
/* C93F8 80132CF8 10400019 */  beqz      $v0, .L80132D60
/* C93FC 80132CFC 00941024 */   and      $v0, $a0, $s4
/* C9400 80132D00 54400018 */  bnel      $v0, $zero, .L80132D64
/* C9404 80132D04 26310001 */   addiu    $s1, $s1, 1
/* C9408 80132D08 80A3001D */  lb        $v1, 0x1d($a1)
/* C940C 80132D0C 10730006 */  beq       $v1, $s3, .L80132D28
/* C9410 80132D10 00921024 */   and      $v0, $a0, $s2
/* C9414 80132D14 3C028015 */  lui       $v0, 0x8015
/* C9418 80132D18 8C425D88 */  lw        $v0, 0x5d88($v0)
/* C941C 80132D1C 54430011 */  bnel      $v0, $v1, .L80132D64
/* C9420 80132D20 26310001 */   addiu    $s1, $s1, 1
/* C9424 80132D24 00921024 */  and       $v0, $a0, $s2
.L80132D28:
/* C9428 80132D28 14400002 */  bnez      $v0, .L80132D34
/* C942C 80132D2C 24020011 */   addiu    $v0, $zero, 0x11
/* C9430 80132D30 2402000D */  addiu     $v0, $zero, 0xd
.L80132D34:
/* C9434 80132D34 AE020000 */  sw        $v0, ($s0)
/* C9438 80132D38 3C028013 */  lui       $v0, 0x8013
/* C943C 80132D3C 244221A4 */  addiu     $v0, $v0, 0x21a4
/* C9440 80132D40 0200202D */  daddu     $a0, $s0, $zero
/* C9444 80132D44 AE050008 */  sw        $a1, 8($s0)
/* C9448 80132D48 AE02000C */  sw        $v0, 0xc($s0)
/* C944C 80132D4C 0C047644 */  jal       queue_render_task
/* C9450 80132D50 AE000004 */   sw       $zero, 4($s0)
/* C9454 80132D54 8C430000 */  lw        $v1, ($v0)
/* C9458 80132D58 34630002 */  ori       $v1, $v1, 2
/* C945C 80132D5C AC430000 */  sw        $v1, ($v0)
.L80132D60:
/* C9460 80132D60 26310001 */  addiu     $s1, $s1, 1
.L80132D64:
/* C9464 80132D64 2A220100 */  slti      $v0, $s1, 0x100
/* C9468 80132D68 1440FFD3 */  bnez      $v0, .L80132CB8
/* C946C 80132D6C 00000000 */   nop      
/* C9470 80132D70 8FBF0038 */  lw        $ra, 0x38($sp)
/* C9474 80132D74 8FB50034 */  lw        $s5, 0x34($sp)
/* C9478 80132D78 8FB40030 */  lw        $s4, 0x30($sp)
/* C947C 80132D7C 8FB3002C */  lw        $s3, 0x2c($sp)
/* C9480 80132D80 8FB20028 */  lw        $s2, 0x28($sp)
/* C9484 80132D84 8FB10024 */  lw        $s1, 0x24($sp)
/* C9488 80132D88 8FB00020 */  lw        $s0, 0x20($sp)
/* C948C 80132D8C 03E00008 */  jr        $ra
/* C9490 80132D90 27BD0040 */   addiu    $sp, $sp, 0x40
