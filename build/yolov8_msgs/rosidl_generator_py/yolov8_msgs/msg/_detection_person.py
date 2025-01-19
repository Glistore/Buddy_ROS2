# generated from rosidl_generator_py/resource/_idl.py.em
# with input from yolov8_msgs:msg/DetectionPerson.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DetectionPerson(type):
    """Metaclass of message 'DetectionPerson'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('yolov8_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'yolov8_msgs.msg.DetectionPerson')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__detection_person
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__detection_person
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__detection_person
            cls._TYPE_SUPPORT = module.type_support_msg__msg__detection_person
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__detection_person

            from std_msgs.msg import String
            if String.__class__._TYPE_SUPPORT is None:
                String.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DetectionPerson(metaclass=Metaclass_DetectionPerson):
    """Message class 'DetectionPerson'."""

    __slots__ = [
        '_inside',
        '_steal',
        '_count_people',
    ]

    _fields_and_field_types = {
        'inside': 'boolean',
        'steal': 'boolean',
        'count_people': 'std_msgs/String',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'String'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.inside = kwargs.get('inside', bool())
        self.steal = kwargs.get('steal', bool())
        from std_msgs.msg import String
        self.count_people = kwargs.get('count_people', String())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.inside != other.inside:
            return False
        if self.steal != other.steal:
            return False
        if self.count_people != other.count_people:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def inside(self):
        """Message field 'inside'."""
        return self._inside

    @inside.setter
    def inside(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'inside' field must be of type 'bool'"
        self._inside = value

    @builtins.property
    def steal(self):
        """Message field 'steal'."""
        return self._steal

    @steal.setter
    def steal(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'steal' field must be of type 'bool'"
        self._steal = value

    @builtins.property
    def count_people(self):
        """Message field 'count_people'."""
        return self._count_people

    @count_people.setter
    def count_people(self, value):
        if __debug__:
            from std_msgs.msg import String
            assert \
                isinstance(value, String), \
                "The 'count_people' field must be a sub message of type 'String'"
        self._count_people = value
